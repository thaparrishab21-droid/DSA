class Solution {
public:
    string removeKdigits(string num, int k) {
     int n=num.size();
     stack<char> st;
     if(k >= n)
        return "0";
    
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && st.top() > num[i]  && k > 0)
        {
            st.pop();
            k--;
        }
        st.push(num[i]);
    }
    while(k!=0)
    {
        st.pop();
        k--;
    }
    string ans;
    while(!st.empty())
    {
        ans +=(char)st.top();
        st.pop();
    }
    n=ans.size();
    while( !ans.empty() && ans.back()=='0')
        ans.pop_back();
    reverse(ans.begin(),ans.end());
    if(ans.empty()) return "0";
    return ans;    
    }
};

