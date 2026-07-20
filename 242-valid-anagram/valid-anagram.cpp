class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<int,int>mp;
        for(char c: s){
            mp[c-'a']++;
        }
        for(char c:t){
            if(mp.find(c-'a')==mp.end()|| mp[c-'a'] == 0) return false;
            else{
                mp[c-'a']--;
            }
        }
        return true;
    }
};