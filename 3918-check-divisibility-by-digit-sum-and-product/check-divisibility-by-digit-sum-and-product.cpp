class Solution {
public:
    bool checkDivisibility(int n) {
        int temp=n;
        int su=0,pro=1;
        while(temp>0){
            int digit=temp%10;
            temp/=10;
            su+=digit;
            pro*=digit;
        }
        return (n%(su+pro)==0);
    }
};