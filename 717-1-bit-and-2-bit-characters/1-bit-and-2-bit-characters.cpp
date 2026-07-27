class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n=bits.size();
        int cnt=0;
        if(n==1 || bits[n-2]==0) return true;
        else{
            for(int i=n-2;i>=0;i--){
                if(bits[i]==0) break;
                else cnt++;
            }
        }
        return (cnt%2)? false : true;
    }
};