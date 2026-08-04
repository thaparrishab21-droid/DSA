class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>ans;
        int curr=nums[0]+1;
        for(int i=1;i<n;i++){
            if(nums[i]!=curr){
                ans.push_back(curr);
                i--;
            }
            curr++;
        }
        return ans;
    }
};