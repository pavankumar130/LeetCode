/*
class Solution {
public:
bool solve(int ind, vector<int>&gas, vector<int>&cost){
    int fuel=0;
    int n=gas.size();
    for(int i=ind; i<(ind+n);i++){
        fuel+=gas[i%n];
        if(fuel < cost[i%n] ){
            return false;
        }
        fuel-=cost[i%n];
    }
    return true;
}
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        for(int i=0;i<n;i++){
            if( solve(i,gas,cost) == true ){
                return i;
            }
        }
        return -1;
    }
};
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int maxi=0;
        int curr=0;
        int start=0;
        for(int i=0;i<gas.size();i++){
            int diff=gas[i]-cost[i];
            maxi+=diff;
            curr+=diff;
            if(curr < 0){
                curr=0;
                start=i+1;
            }
        }
        if(maxi < 0){
            return -1;
        }
        return start;
    }
};