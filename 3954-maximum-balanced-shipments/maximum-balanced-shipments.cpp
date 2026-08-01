class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int n=weight.size();
        int cnt=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            if(weight[i]>maxi){
                maxi=weight[i];
            }
            else if(weight[i]==maxi) continue;
            else{
                cnt++;
                maxi=0;
            }
        }
        return cnt;
    }
};