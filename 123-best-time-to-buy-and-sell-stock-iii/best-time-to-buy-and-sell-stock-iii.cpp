class Solution {
public:
int f4(int ind,int buy,int n,int cap,vector<int>& prices,vector<vector<vector<int>>>&dp){
        if(ind==n || cap==0) return 0;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        if(buy){
            return dp[ind][buy][cap]=max(-prices[ind]+f4(ind+1,0,n,cap,prices,dp),
                                    f4(ind+1,1,n,cap,prices,dp));
        }
        else{
            return dp[ind][buy][cap]=max(prices[ind]+f4(ind+1,1,n,cap-1,prices,dp),
                                    f4(ind+1,0,n,cap,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<double>>>dp(n+1,vector<vector<double>>(2,vector<double>(3,0)));
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){
                for(int cap=1;cap<=2;cap++){
                    if(buy){
                        dp[ind][buy][cap]=max(-prices[ind]+dp[ind+1][0][cap],
                                                dp[ind+1][1][cap]);
                    }
                    else{
                        dp[ind][buy][cap]=max(prices[ind]+dp[ind+1][1][cap-1],
                                                dp[ind+1][0][cap]);
                    }
                }
            }
        }
        return (int)dp[0][1][2];
    }
};