class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights){
            int u=it[0];
            int v=it[1];
            int d=it[2];
            adj[u].push_back({v,d});
        }
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        queue<pair<int,pair<int,int>>> q;
        //stops node netwt
        q.push({0,{src,0}});
        while(!q.empty()){
            auto i=q.front();
            int stops=i.first;
            int node=i.second.first;
            int cost=i.second.second;
            q.pop();
            if(stops > k) continue;
           
            for(auto it:adj[node]){
                int adjn=it.first;
                int ewt=it.second;
                if(cost+ewt<dist[adjn]){
                    dist[adjn]=cost+ewt;
                    q.push({stops+1,{adjn,dist[adjn]}});
                }
            }
        }
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};