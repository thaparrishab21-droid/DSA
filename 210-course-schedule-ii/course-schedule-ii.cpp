class Solution {
public:
    bool dfs3(int course,vector<int>&ans,vector<vector<int>>&adj,vector<int>&vis,vector<int>&pathvis){
        vis[course]=1;
        pathvis[course]=1;
       
        for(auto it : adj[course]){
            if(!vis[it]){
                if(dfs3(it,ans,adj,vis,pathvis)){
                    return true;
                }
            }
            else if(pathvis[it]) return true;
        }
        pathvis[course]=0;
        ans.push_back(course);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto &it : prerequisites){
            int a = it[0];
            int b = it[1];

            adj[b].push_back(a);
        }
        vector<int>vis(numCourses);
        vector<int>pathvis(numCourses);
        vector<int>ans;
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs3(i,ans,adj,vis,pathvis))  return {};
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};