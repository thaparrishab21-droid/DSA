class Solution {
public:
    int day(vector<int>& weights,int cap){
        int load=0;
        int days=1;
        for(int i=0;i<weights.size();i++){
            if(load+weights[i]>cap){
                days++;
                load=weights[i];
            }
            else load+=weights[i];
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int ans=0;
        int low=INT_MIN;
        for(auto w:weights) low=max(low,w);
        int high=0;
        for(auto w:weights) high+=w;
        while(low<=high){
            int mid=(low+high)/2;
            int d=day(weights,mid);
            if(d<=days) {
                ans=mid;
                high=mid-1;
            }
            else  low=mid+1;
        }
        return ans;
    }
};