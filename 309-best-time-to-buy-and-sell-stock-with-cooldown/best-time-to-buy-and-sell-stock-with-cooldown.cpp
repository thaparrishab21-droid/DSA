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
        vector<int>front1(2,0),front2(2,0),curr(2,0);
        for(int ind=n-1;ind>=0;ind--){
            curr[1]=max(-prices[ind]+front1[0],front1[1]);
            curr[0]=max(prices[ind]+front2[1],front1[0]);
            front2=front1;
            front1=curr;
        }
        return front1[1];
    }
};