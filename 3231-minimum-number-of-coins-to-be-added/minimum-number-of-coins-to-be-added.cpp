class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        
        int n=coins.size();
        long long prefix = 0;
        int id=0;
        sort(coins.begin(),coins.end());
        int res = 0;
        for(int t=1; t<=target; t++){
            if(id < n && coins[id] <= t){
                prefix+=coins[id]; 
                id++;
            }
            else{  // coins[id] > t 
                if(prefix >= t){
                    continue;
                }
                prefix+=t; // i want to add that coin to achive that target
                res++;
            }
        }
        return res;
    }
};