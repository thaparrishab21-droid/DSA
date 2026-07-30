class Solution {
public:
    string makeGood(string s) {
        string ans="";
        int n=s.size();
        for(char c:s){
            if(!ans.empty() && abs(c-ans.back())==32){
                ans.pop_back();
            }
            else ans+=c;
        }
        return ans;
    }
};