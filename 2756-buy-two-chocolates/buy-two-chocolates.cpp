class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        
        int n=prices.size();
        int secondsmall = 101;
        int small = 101;

        for(int i=0; i<n; i++){
            if(prices[i] < small){
                secondsmall = small ;
                small = prices[i];
            }
            else if(prices[i] < secondsmall){
                secondsmall = prices[i];
            }
        }
        
        if(secondsmall+small <= money){
            return money-(secondsmall+small);
        }
        return money;
    }
};