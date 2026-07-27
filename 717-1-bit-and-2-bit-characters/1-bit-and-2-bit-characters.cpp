class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n=bits.size();
        int ind=0;
        while(ind<n-1){
            if(bits[ind]==0) ind++;
            else ind+=2;
        }
        return ind==n-1;
    }
};