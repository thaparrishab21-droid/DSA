class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        int n=asteroids.size();
        for(int x:asteroids){
            if(x>0) st.push(x);
            else{
                while(!st.empty() && st.top()>0 && st.top()<-x){
                    st.pop();
                }
                if(st.empty() || st.top()<0){
                    st.push(x);
                }
                if (!st.empty() && st.top() == -x) {
                    st.pop();
                }
            }
        }
        vector<int>ans;
        while(!st.empty()){
            int a=st.top();
            ans.push_back(a);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};