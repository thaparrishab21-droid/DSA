class Solution {
public:
    bool check(int n){
        int i=1;
        while (i * i <= n) {
            if (i * i == n)
                return true;
            i++;
        }
        return false;
    }
    bool winnerSquareGame(int n) {
        vector<bool>dp(n+1,false);
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                    int rem=i-j*j;
                    if(dp[rem]==false){
                        dp[i]=true;
                        break;
                    }
                
            }
        }
        return dp[n];

    }
};