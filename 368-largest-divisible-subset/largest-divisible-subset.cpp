class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        int lasti=0;
        vector<int>dp(n,1),hash(n);
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                lasti=i;
            }
        }
        vector<int>ans;
        int ind=lasti;
        while(hash[ind]!=ind){
            ans.push_back(nums[ind]);
            ind=hash[ind];
        }
        ans.push_back(nums[ind]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};