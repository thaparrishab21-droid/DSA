class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0,zeroes=0;
        int n=nums.size();
        int maxi=0;
        while(l<n && r<n){
            if(nums[r]==0){
                zeroes++;
            }
            while(zeroes>k){
                if(nums[l]==0)zeroes--;
                l++;
            }
            maxi = max(maxi, r - l + 1);
            r++;
        } return maxi;
    }
};