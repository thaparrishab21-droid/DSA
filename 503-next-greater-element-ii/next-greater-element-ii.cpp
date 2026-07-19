class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=2*n-2;i>=0;i--){
            int ind=i%n;
            while(!st.empty() && st.top()<=nums[ind]){
                st.pop();
            }
            int greater=st.empty()?-1:st.top();
            ans[ind]=greater;
            st.push(nums[ind]);
        }
        return ans;
    }
};