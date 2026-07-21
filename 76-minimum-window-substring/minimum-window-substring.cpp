class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) {
            return "";
        }
        unordered_map<char,int>charcnt;
        for(char c:t) charcnt[c]++;
        int n=s.size();
        int m=t.size();
        int l=0;
        int minlen=INT_MAX;
        int k=m;
        int start=0;
        for(int r=0;r<n;r++){
            charcnt[s[r]]--;
            if(charcnt[s[r]]>=0){
                k--;
            }
            while(k==0){
                if(r-l+1<minlen){
                    minlen=r-l+1;
                    start=l;
                }
                charcnt[s[l]]++;

                if(charcnt[s[l]] > 0)
                    k++;

                l++;
            }
        }
                if(minlen == INT_MAX)
            return "";

        return s.substr(start, minlen);

    }
};