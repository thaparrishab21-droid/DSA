class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        unordered_map<int,int>mpp;
        vector<int>ans;
        stack<int>st;
        for(int i=n2-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            int greater=st.empty()?-1:st.top();
            mpp[nums2[i]]=greater;
            st.push(nums2[i]);
        }
        for(int x:nums1){
            ans.push_back(mpp[x]);
        }
        return ans;
    }
};