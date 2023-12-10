class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n=prices.size();

        vector<int>dp(n+1, -1);
        dp[n]=0;
        dp[n-1]=prices[n-1];

        for(int i=n-2; i>=0; i--){
            int mini = 1e9;
            for(int j = i+1; j<= min(n, 2*(i+1));  j++){
                mini = min(mini,dp[j]);
            }
            dp[i]= prices[i]+ mini;
        }
        return dp[0];
    }
};