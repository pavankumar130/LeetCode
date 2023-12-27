class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int n = neededTime.size();

        int res = 0;

        int i = 1;
        int j = 0;

        while(i < n){
            
            while(i < n && colors[i] == colors[j]){
                if(neededTime[i] > neededTime[j]){
                    res += neededTime[j];
                    j = i;
                    i++;
                }
                else{
                    res += neededTime[i];
                    i++;
                }
            }
            j = i;
            i++;
        }
        return res;
    }
};