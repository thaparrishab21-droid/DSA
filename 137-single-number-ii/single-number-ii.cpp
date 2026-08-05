class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(mpp[nums[i]]!=3) {
                ans=nums[i];
                break;
            }
        }
        return ans;
    }
};