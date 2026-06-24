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
        vector<int>prev(amount+1,0),curr(amount+1);
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) prev[i]=i/coins[0];
            else prev[i]=1e9;
        }
        for(int i=1;i<n;i++){
            for(int t=0;t<=amount;t++){
                int notake=prev[t];
                int take=INT_MAX;
                if(coins[i]<=t) take=1+curr[t-coins[i]];
                curr[t]=min(take,notake);
            }
            prev=curr;
        }
        if(prev[amount]>=1e9) return -1;
        return prev[amount];
    }
};