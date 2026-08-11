class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum=nums[0];
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]+1==nums[i+1]){
                sum+=nums[i+1];
            }
            else break;
        }
        vector<bool>freq(1300,false);
        for(int it:nums) freq[it]=true;
        int ind=sum;
        while(true){
            if(freq[ind]){
                ind++;
            }
            else break;
        }
        return ind;
    }
};