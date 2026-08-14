class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        int ans=0;
        unordered_map<char,int>mp;
        int l=0;
        for(int r=0;r<n;r++){
            mp[s[r]]++;
            if(mp[s[r]]>2){
                while(mp[s[r]]>2){
                    mp[s[l]]--;
                    l++;
                }
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};