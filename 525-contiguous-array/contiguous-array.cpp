class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int sum=0;
        int ans=0;
        mpp[0]=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) sum--;
            else sum++;
            if(mpp.find(sum)!=mpp.end()){
                ans=max(ans,i-mpp[sum]);
            }
            else mpp[sum]=i;
        }
        return ans;
    }
};