class Solution {
public:
    bool binary(int target,int r,vector<vector<int>>& matrix,int low,int high){
        if(low>high) return false;
        int mid=(low+high)/2;
        if(matrix[r][mid]==target) return true;
        else if(matrix[r][mid]<target){
            return binary(target,r,matrix,mid+1,high);
        }
        else{
            return binary(target,r,matrix,low,mid-1);
        }
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            int low=0;
            int high=m-1;   
            if(binary(target,i,matrix,low,high)) return true;
        }
        return false;
    }
};