class Solution {
public:
    bool check(vector<int>& nums, int k,int mid){
        int cnt=1;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(cnt>k) return false;
            if(sum+nums[i]<=mid){
                sum+=nums[i];
            }
            else{
                cnt++;
                sum=nums[i];
            }
        }
        return cnt<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        if(nums.size()<k)return -1;
        int low=0;
        int high=0;
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++) low=max(nums[i],low);
        for(int i=0;i<n;i++) high+=nums[i];
        while(low<=high){
            int mid=(low+high)/2;
            if(check(nums,k,mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};