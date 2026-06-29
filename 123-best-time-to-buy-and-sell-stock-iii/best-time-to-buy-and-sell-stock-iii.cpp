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
        vector<vector<int>>ahead(2,vector<int>(3,0));
        vector<vector<int>>curr(2,vector<int>(3,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){
                for(int cap=1;cap<=2;cap++){
                    if(buy){
                        curr[buy][cap]=max(-prices[ind]+ahead[0][cap],
                                                ahead[1][cap]);
                    }
                    else{
                        curr[buy][cap]=max(prices[ind]+ahead[1][cap-1],
                                                ahead[0][cap]);
                    }
                }
                ahead=curr;
            }
        }
        return ahead[1][2];
    }
};