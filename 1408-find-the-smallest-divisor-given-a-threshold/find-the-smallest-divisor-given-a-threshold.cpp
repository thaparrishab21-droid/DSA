class Solution {
public:
    bool result(vector<int>& nums, int threshold,int divisor){
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=ceil((double)nums[i]/divisor);
        }
        return ans<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int low=1;
        int high=0;
        for(int i=0;i<n;i++) high=max(high,nums[i]);
        while(low<=high){
            int mid=(low+high)/2;
            bool cando=result(nums,threshold,mid);
            if(cando) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};