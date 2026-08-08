class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<int> result;

        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;

        for(auto it : nums1) {
            mp1[it]++;
        }

        for(auto it : nums2) {
            mp2[it]++;
        }
        vector<int>ans;
        for(auto it:mp1){
            if(mp2.find(it.first)!=mp2.end()){
                while(mp1[it.first]>0 && mp2[it.first]>0){
                    ans.push_back(it.first);
                    mp1[it.first]--;
                    mp2[it.first]--;
                }
            }
        }
        return ans;
    }
};