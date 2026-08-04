class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        unordered_set<int>st(nums.begin(),nums.end());
        vector<int>ans;
        for(int i=nums[0];i<=nums[n-1];i++){
            if(!st.count(i)) ans.push_back(i);
        }
        return ans;
    }
};