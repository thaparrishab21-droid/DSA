class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        int start=0,end=0;
        for(int i=0;i<n;i++){
            int more=target-nums[i];
            if(mpp.count(more)){
                start=mpp[more];
                end=i;
            }
            else mpp[nums[i]]=i;
        }
        return {start+1,end+1};
    }
};