class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans=0;
        for(auto it:patterns){
            if(word.contains(it)) ans++;
        }
        return ans;
    }
};