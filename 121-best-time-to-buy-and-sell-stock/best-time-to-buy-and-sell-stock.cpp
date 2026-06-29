class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mini=1e9;
        int maxp=0;
        for(int i=0;i<n;i++){
            if(prices[i]<mini) mini=prices[i];
            maxp=max(maxp,prices[i]-mini);
        }
        return maxp;
    }
};