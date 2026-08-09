class Solution {
public:
    int check(int i,int m,vector<int>& piles,vector<vector<int>>&dp,vector<int>& suffix){
        if(i>=piles.size()) return 0;
        if(dp[i][m]!=-1) return dp[i][m];
        int best=0;
        int total=suffix[i];
        for(int x=1;x<=2*m && i+x<=piles.size();x++){
            int remaining=suffix[i+x];
            int opp=check(i+x,max(x,m),piles,dp,suffix);
            best=max(best,total-opp);
        }
        return dp[i][m]=best;
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<int>suffix(n+1,0);
        for(int i=n-1;i>=0;i--){
            suffix[i]=suffix[i+1]+piles[i];
        }
        vector<vector<int>>dp(n,vector<int>(2*n+1,-1));
        return check(0,1,piles,dp,suffix);
    }
};