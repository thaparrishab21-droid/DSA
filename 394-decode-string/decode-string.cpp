class Solution {
public:
    string decodeString(string s) {
        stack<string>st;
        int n=s.size();
        string current="";
        stack<int>numst;
        int num=0;
        for(char c:s){
            if(isdigit(c)){
                num=num*10+(c-'0');
            }
            else if(c=='['){
                numst.push(num);
                st.push(current);
                current="";
                num=0;
            }
            else if(c==']'){
                int rep=numst.top();
                numst.pop();
                string prev=st.top();
                st.pop();
                string temp="";
                for(int i=0;i<rep;i++){
                    temp+=current;
                }
                current=prev+temp;
            }
            else current+=c;
        }
        return current;
    }
};