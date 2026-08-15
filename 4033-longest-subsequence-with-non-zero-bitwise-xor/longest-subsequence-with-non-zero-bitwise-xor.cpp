class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int xr=0;
        int cnt0=0;
        for(int i=0;i<n;i++){
            xr^=nums[i];
            if(nums[i]==0) cnt0++;
        }
        if(xr) return n;
        if(xr==0 && cnt0!=n) return n-1;
        return 0;
    }
};