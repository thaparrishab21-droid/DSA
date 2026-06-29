class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<double>>>dp(n+1,vector<vector<double>>(2,vector<double>(k+1,0)));
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){
                for(int cap=1;cap<=k;cap++){
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
        return (int)dp[0][1][k];
    }
};