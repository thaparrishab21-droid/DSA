class Solution {
public:
    int f8(int i,int j,vector<int>& cuts,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=1e9;
        for(int ind=i;ind<=j;ind++){
            int cost=cuts[j+1]-cuts[i-1]+ f8(i,ind-1,cuts,dp)+f8(ind+1,j,cuts,dp);
            mini=min(mini,cost);
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int s=cuts.size();
        vector<vector<int>>dp(s+1,vector<int>(s+1,-1));
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(),cuts.end());
        return f8(1,s,cuts,dp);
    }
};