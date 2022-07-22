class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       int loss =0, msf=0,start=0;
        for(int i =0; i<gas.size();i++){
            msf += gas[i]-cost[i];
            if(msf<0){
                start = i+1;
                loss += msf;
                msf = 0;
            }
        }
        if(msf+loss>=0){
            return start;
        }
        else{
            return -1;
        }
    }
};
