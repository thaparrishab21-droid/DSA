class Solution {
public:
    int count(int n){
        int cnt=0;
        while(n>0){
            if(n&1) cnt++;
            n>>=1;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++){
            int a=count(i);
            ans.push_back(a);
        }
        return ans;
    }
};