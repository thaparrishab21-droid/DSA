class Solution {
public:
    
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int fuel=0;
        int total=0;
        int start=0;
        for(int i=0;i<n;i++){
            fuel+=gas[i]-cost[i];
            total+=gas[i]-cost[i];
            if(fuel<0){
                start=i+1;
                fuel=0;
            }
        }
        return total>=0?start:-1;
    }
};