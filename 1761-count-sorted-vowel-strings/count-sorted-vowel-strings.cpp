class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>>dp(n+1,vector<int>(6,0));
        for(int j=1;j<=5;j++) dp[1][j]=j;
        for(int i=1;i<=n;i++) dp[i][1]=1;
        for(int i=2;i<=n;i++){
            for(int j=2;j<=5;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[n][5];
    }
};