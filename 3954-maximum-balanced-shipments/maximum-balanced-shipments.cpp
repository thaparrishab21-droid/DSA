class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int n=weight.size();
        int cnt=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,weight[i]);
            if(weight[i]<maxi){
                cnt++;
                maxi=0;
            }
            
        }
        return cnt;
    }
};