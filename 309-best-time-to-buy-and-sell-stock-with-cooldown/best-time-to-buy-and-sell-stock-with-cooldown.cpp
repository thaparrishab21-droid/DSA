class Solution {
public:
    int f5(int ind,int buy,int n,vector<int>& prices,vector<vector<int>>&dp){
        if(ind>=n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy){
            return dp[ind][buy]=max(-prices[ind]+f5(ind+1,0,n,prices,dp),f5(ind+1,1,n,prices,dp));
        }
        else return dp[ind][buy]=max(prices[ind]+f5(ind+2,1,n,prices,dp),f5(ind+1,0,n,prices,dp));
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f5(0,1,n,prices,dp);
    }
};