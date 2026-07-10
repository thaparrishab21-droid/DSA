class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(k>=arr[i]) k++;
            else break;
        }
        return k;
    }
};