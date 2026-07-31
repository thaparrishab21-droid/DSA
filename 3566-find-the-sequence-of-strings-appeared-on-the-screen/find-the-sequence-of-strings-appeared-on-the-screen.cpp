class Solution {
public:
    vector<string> stringSequence(string target) {
        int n=target.size();
        vector<string>ans;
        string temp="";
        for(char ch:target){
            for(char c='a';c<=ch;c++){
                ans.push_back(temp+c);
            }
            temp+=ch;
        }
        return ans;
    }
};