class Solution {
public:
    int f11(int i,int n,vector<int>& arr, int k,vector<int>&dp){
        if(i==n) return 0;
        int len=0;
        int maxAns=INT_MIN;
        int maxi=INT_MIN;
        if(dp[i]!=-1) return dp[i];
        for(int j=i;j<min(n,i+k);j++){
            len++;
            maxi=max(maxi,arr[j]);
            int sum=len*maxi+f11(j+1,n,arr,k,dp);
            maxAns=max(maxAns,sum);
        }
        return dp[i]=maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n,-1);
        return f11(0,n,arr,k,dp);
    }
};