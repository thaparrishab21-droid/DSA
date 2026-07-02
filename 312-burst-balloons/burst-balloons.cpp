class Solution {
public:
    int f9(int i,int j,vector<int>& nums,vector<vector<int>>&dp){
        if(i>j) return 0;
        int maxi=-1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int ind=i;ind<=j;ind++){
            int points=nums[i-1]*nums[ind]*nums[j+1]+f9(i,ind-1,nums,dp)+f9(ind+1,j,nums,dp);
            maxi=max(maxi,points);
        }
        return dp[i][j]=maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        int maxi=-1e9;
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        for(int i=n;i>=1;i--){
            for(int j=i;j<=n;j++){
                int maxi=-1e9;
                for(int ind=i;ind<=j;ind++){
                    int points=nums[i-1]*nums[ind]*nums[j+1]+dp[i][ind-1]+dp[ind+1][j];
                    maxi=max(maxi,points);
                }
                dp[i][j]=maxi;
            }
        }
        return dp[1][n];
    }
};