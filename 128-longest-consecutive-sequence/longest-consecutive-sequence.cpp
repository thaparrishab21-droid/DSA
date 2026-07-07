class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n=nums.size();
        int cnt=1;
        int maxlen=1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            if(nums[i+1] == nums[i]) continue;
            if(nums[i]==nums[i+1]-1){
                cnt++;
                maxlen=max(maxlen,cnt);
            }
            else cnt=1;
        }
        return maxlen;
    }
    
};