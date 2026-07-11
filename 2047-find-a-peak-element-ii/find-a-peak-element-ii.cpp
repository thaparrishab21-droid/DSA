class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int>ans;
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int col=0;
            for(int i=0;i<m;i++){
                if(mat[mid][col]<mat[mid][i]){
                    col=i;
                }
            }
            int top=(mid>0)?mat[mid-1][col]:-1;
            int bottom=(mid<n-1)?mat[mid+1][col]:-1;
            if(mat[mid][col] > top && mat[mid][col] > bottom){
                ans.push_back(mid);
                ans.push_back(col);
                return ans;
            }
            else if(mat[mid][col] < top) high=mid-1;
            else if(mat[mid][col] < bottom) low=mid+1;
        }
        return {-1,-1};
    }
};