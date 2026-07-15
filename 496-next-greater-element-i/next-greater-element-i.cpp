class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int ind=-1;
        vector<int>ans;
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(nums1[i]==nums2[j]){
                    ind=j;
                    break;
                }
            }int greater=-1;
            for(int k=ind+1;k<n2;k++){
                if(nums2[k]>nums1[i]){
                    greater=nums2[k];
                    break;
                }
            }
            ans.push_back(greater);
        }
        return ans;
    }
};