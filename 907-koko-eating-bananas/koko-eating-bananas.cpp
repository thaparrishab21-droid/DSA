class Solution {
public:
    long long time(vector<int>& piles,int k){
        long long restime=0;
        for(int i=0;i<piles.size();i++){
            restime+=ceil((double)piles[i]/k);
        }
        return restime;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        sort(piles.begin(),piles.end());
        int high=piles[n-1];
        int low=1;
        int ans=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            long long ti=time(piles,mid);
            if(ti<=h){
                ans=min(ans,mid);
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};