class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        mp[0]=-1;
        int pre=0;
        for(int i=0;i<n;i++){
            pre+=nums[i];
            int rem=pre%k;
            if(mp.count(rem)){
                if(i-mp[rem]>=2) return true;
            }
            else mp[rem]=i;
        }
        return false;
    }
};