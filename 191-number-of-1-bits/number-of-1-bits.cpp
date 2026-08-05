class Solution {
public:
    int hammingWeight(int n) {
        int cnt=0;
        int temp=n;
        while(temp>0){
            if(temp & 1) cnt++;
            temp>>=1;
        }
        return cnt;
    }
};