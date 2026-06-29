class Solution {
public:
    int f3(int ind,int buy,int n,vector<int>& prices,vector<vector<int>>&dp){
        if(ind==n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy){
            return dp[ind][buy]=max(-prices[ind]+f3(ind+1,0,n,prices,dp),
                                    f3(ind+1,1,n,prices,dp));
        }
        else{
            return dp[ind][buy]=max(prices[ind]+f3(ind+1,1,n,prices,dp),
                                    f3(ind+1,0,n,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>ahead(2,0),curr(2,0);
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                if(buy){
                    curr[buy]=max(-prices[ind]+ahead[0],
                                        ahead[1]);
                }
                else{
                    curr[buy]=max(prices[ind]+ahead[1],
                                        ahead[0]);
                }
            }
            ahead=curr;
        }
        return ahead[1];
    }
};