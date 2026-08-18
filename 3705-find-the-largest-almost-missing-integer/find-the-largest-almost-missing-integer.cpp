class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int maxi=INT_MIN;
        for(int x:nums){
            mp[x]++;
            maxi=max(maxi,x);
        }
        if (k==1){
            int ans=-1;
            for(auto& [val,cnt]:mp){
                if (cnt==1) ans=max(ans,val);
            }
            return ans;
        }
        if(k==n) return maxi;
        if(mp[nums[n-1]]>1 && mp[nums[0]]==1) return nums[0];
        else if(mp[nums[n-1]]==1 && mp[nums[0]]>1) return nums[n-1];
        else if(mp[nums[n-1]]==1 && mp[nums[0]]==1)return max(nums[0],nums[n-1]);
        else return -1;
    }
};