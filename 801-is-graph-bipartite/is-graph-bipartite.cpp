class Solution {
public:
    bool dfs8(int in,int cl,vector<vector<int>>&graph,vector<int>&col){
        int n=graph.size();
        int m=graph[0].size();
        col[in]=cl;
        for(auto it:graph[in]){
            if(col[it]==-1){
                if(col[in]==0) {
                    if(!dfs8(it,1,graph,col)) return false;
                }
                else if(col[in]==1){
                    if(!dfs8(it,0,graph,col)) return false;
                }
            }
            else if(col[it] == cl) {
                    return false;
                }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        
        vector<int>col(n,-1);
        
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                if(!dfs8(i,0,graph,col)) return false;
            }
        }
        return true;
    }
};