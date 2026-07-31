class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        vector<int>freq(26,0);
        int cnt=0;
        for(char c:word){
            freq[c-'a']++;
        }
        sort(freq.begin(),freq.end());
        reverse(freq.begin(),freq.end());
        for(int i=0;i<freq.size();i++){
            if(freq[i]==0) break;
            else cnt+=(i/8+1)*freq[i];
        }
        return cnt;
    }
};