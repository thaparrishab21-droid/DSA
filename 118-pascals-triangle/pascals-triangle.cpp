class Solution {
public:
    int nCr(int n ,int r){
        int res=1;
        for(int i=0;i<r;i++){
            res*=(n-i);
            res/=(i+1);
        }
        return res;
    }
    vector<vector<int>> generate(int n) {
       vector<vector<int>>ans;
       for(int i=0;i<n;i++){
        vector<int>row;
        for(int j=0;j<=i;j++){
            row.push_back(nCr(i,j));
        }
        ans.push_back(row);
       }
        return ans;

    }
};