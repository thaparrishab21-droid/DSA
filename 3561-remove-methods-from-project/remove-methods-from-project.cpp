class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& sus) {
        sus[node] = 1;
        for (int next : adj[node]) {
            if (sus[next] == 0) {
                dfs(next, adj, sus);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        for(auto it:invocations){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }
        vector<int>sus(n,0);
        dfs(k,adj,sus);
        for (auto edge : invocations) {
            int u = edge[0];
            int v = edge[1];

            if (sus[u] == 0 && sus[v] == 1) {
                vector<int> ans;
                for (int i = 0; i < n; i++) {
                    ans.push_back(i);
                }
                return ans;
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(sus[i]==0) ans.push_back(i);
        }
        return ans;
    }
};