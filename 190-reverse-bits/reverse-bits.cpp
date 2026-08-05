class Solution {
public:
    int reverseBits(int n) {
        int ans=0;
        int i=1;
        while(n>0){
            if(n&1){
                ans+=pow(2,32-i);
            }
            n>>=1;
            i++;
        }
        return ans;
    }
};