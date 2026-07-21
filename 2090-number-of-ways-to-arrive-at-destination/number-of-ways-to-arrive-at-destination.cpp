class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adjm(n);
        int MOD=(int)(1e9+7);
        for(auto it:roads){
            int u=it[0];
            int v=it[1];
            int d=it[2];
            adjm[u].push_back({v,d});
            adjm[v].push_back({u,d});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        //dist,node
        pq.push({0,0});
        vector<long long> dist(n, LLONG_MAX);
        vector<long long>ways(n,0);
        ways[0]=1;
        dist[0]=0;
        while(!pq.empty()){
            int node= pq.top().second;
            long long d=pq.top().first;
            pq.pop();
            if(d > dist[node]) continue;
            for(auto it:adjm[node]){
                int adjn=it.first;
                long long ewt=it.second;
                if(d+ewt<dist[adjn]){
                    dist[adjn]=d+ewt;
                    ways[adjn]=ways[node];
                    pq.push({dist[adjn],adjn});
                }
                else if(d+ewt==dist[adjn]){
                    ways[adjn]=(ways[adjn]+ways[node])%MOD;
                }
            }
        }
        return ways[n-1]%MOD;
    }
};