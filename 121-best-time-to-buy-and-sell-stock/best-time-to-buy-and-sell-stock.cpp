class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int n=prices.size();
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(mini>prices[i]) mini=prices[i];
            else{
                ans=max(ans,prices[i]-mini);
            }
        }
        return ans;
    }
};