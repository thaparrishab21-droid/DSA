class Solution {
public:
    int perfectSum(vector<int>&arr, int k){
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(k+1,0));
        if(arr[0]==0) dp[0][0]=2;
        else dp[0][0]=1;
        if(arr[0]!=0 && arr[0] <= k) dp[0][arr[0]]=1;
        for(int i=1;i<n;i++){
            for(int t=0;t<=k;t++){
                int notpick=dp[i-1][t];
                int pick = 0;
                if(arr[i] <= t)
                    pick = dp[i-1][t-arr[i]];
                dp[i][t]= notpick + pick;
            }
        }
        return dp[n-1][k];
	}

int countPartitions(vector<int>& arr, int d){
    int n=arr.size();
    int sum=0;
    for(int i=0;i<n;i++) sum+=arr[i];
    if(sum<d || (sum-d)%2) return 0;
    return perfectSum(arr,(sum-d)/2);
}
    
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums,target);

    }
};