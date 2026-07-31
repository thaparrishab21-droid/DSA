class Solution {
public:
    bool checkprime(int num){
        if(num < 2) return false;
        for(int i = 2; i * i <= num; i++){
            if(num % i == 0) return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int ans=0;
        for(int i=left;i<=right;i++){
            int cnt=0;
            int temp=i;
            while(temp>0){
                cnt+=temp&1;
                temp>>=1;
            }
            bool prime=checkprime(cnt);
            if(prime) ans++;
        }
        return ans;
    }
};