class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(auto it:nums) freq[it]++;
        vector<vector<int>>list(nums.size()+1);
        for(auto it:freq){
            list[it.second].push_back(it.first);
        }
        vector<int>ans;
        for(int i=nums.size();i>=0;i--){
            for(int j=0;j<list[i].size() && ans.size()<k;j++){
                ans.push_back(list[i][j]);
                if(ans.size()==k) break;
            }
        }
        return ans;
    }
};