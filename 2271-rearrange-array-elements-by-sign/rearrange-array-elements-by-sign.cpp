class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>negi;
        vector<int>posi;
        for(int i=0;i<n;i++){
            if(nums[i]<0) negi.push_back(nums[i]);
            if(nums[i]>0) posi.push_back(nums[i]);
        }
        vector<int>ans(n);
        int j=0;
        for(int i=0;i<posi.size();i++){
            ans[j]=posi[i];
            j+=2;
        }
        int k=1;
        for(int i=0;i<negi.size();i++){
            ans[k]=negi[i];
            k+=2;
        }
        return ans;
    }
};