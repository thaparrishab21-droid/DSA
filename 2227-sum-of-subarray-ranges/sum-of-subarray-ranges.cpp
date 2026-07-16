class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        int n=arr.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            int smallest=arr[i];
            int largest=arr[i];
            for(int j=i;j<n;j++){
                smallest=min(arr[j],smallest);
                largest=max(arr[j],largest);
                ans+=(largest-smallest);
            }
        }
        return ans;
    }
};