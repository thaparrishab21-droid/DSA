class Solution {
public:
    int f(int ind,vector<int>& coins, int amount,vector<vector<int>>&dp){
        if(ind==0){
            if(amount%coins[0]==0) return amount/coins[0];
            return 1e9;
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int take=INT_MAX;
        if(coins[ind]<=amount) take=1+f(ind,coins,amount-coins[ind],dp);
        int notake=f(ind-1,coins,amount,dp);
        return dp[ind][amount]=min(take,notake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) dp[0][i]=i/coins[0];
            else dp[0][i]=1e9;
        }
        for(int i=1;i<n;i++){
            for(int t=0;t<=amount;t++){
                int notake=dp[i-1][t];
                int take=INT_MAX;
                if(coins[i]<=t) take=1+dp[i][t-coins[i]];
                dp[i][t]=min(take,notake);
            }
        }
        if(dp[n-1][amount]>=1e9) return -1;
        return dp[n-1][amount];
    }
};