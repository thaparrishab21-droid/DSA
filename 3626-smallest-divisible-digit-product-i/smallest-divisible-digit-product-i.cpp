class Solution {
public:
    bool check(int n,int t){
        int pro=1;
        while(n>0){
            int a=n%10;
            n/=10;
            pro*=a;
        }
        return pro%t==0;
    }
    int smallestNumber(int n, int t) {
        for(int i=n;i<INT_MAX;i++){
            bool c=check(i,t);
            if(c) return i;
        }
        return 0;
    }
};