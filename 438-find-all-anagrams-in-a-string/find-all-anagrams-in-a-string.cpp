class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> ans;

        if (s.size() < p.size())
            return ans;

        vector<int> pFreq(26,0);
        vector<int> winFreq(26,0);

        for(char ch:p)
            pFreq[ch-'a']++;

        int k = p.size();

        for(int i=0;i<s.size();i++){

            // add current character
            winFreq[s[i]-'a']++;

            // remove left character
            if(i>=k)
                winFreq[s[i-k]-'a']--;

            // compare
            if(winFreq==pFreq)
                ans.push_back(i-k+1);
        }

        return ans;
    }
};