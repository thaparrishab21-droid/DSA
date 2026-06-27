class Solution {
public:
    int f1(int i,int j ,string s, string t,vector<vector<int>>&dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j]=f1(i-1,j-1,s,t,dp);
        else{
            return dp[i][j] = 1 + min({
                f1(i-1, j, s, t, dp),     // delete
                f1(i-1, j-1, s, t, dp),   // replace
                f1(i, j-1, s, t, dp)      // insert
            });
        }
    }
    int minDistance(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<int>prev(m+1,0),curr(m+1,0);
        for(int j=1;j<=m;j++) prev[j]=j;
        for(int i=1;i<=n;i++){
            curr[0]=i;
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) curr[j]=prev[j-1];
                else{
                    curr[j] = 1 + min({
                        prev[j],     // delete
                        prev[j-1],   // replace
                        curr[j-1]      // insert
                    });
                }
            }
            prev=curr;
        }
        return prev[m];
    }
};