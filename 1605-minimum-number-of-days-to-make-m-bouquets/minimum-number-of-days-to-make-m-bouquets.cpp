class Solution {
public:
    bool days(vector<int>& bloomDay, int m, int k, int d){
        int cnt=0,bou=0;
        for(auto i:bloomDay){
            if(i<=d){
                cnt++;
                if(cnt==k){
                    bou++;
                    cnt=0;
                }
            }
            else cnt=0;
        }
        return bou>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m * k > bloomDay.size())
            return -1;
        int n=bloomDay.size();
        int low=1e9;
        int high=0;
        for(auto f:bloomDay) {
            high=max(high,f);
            low=min(low,f);
        }
        while(low<=high){
            int mid=(low+high)/2;
            bool cando=days(bloomDay,m,k,mid);
            if(cando){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};