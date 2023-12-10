class Solution {
public:
int solve(int i, int n, vector<int>&prices, vector<int>&dp){
    if(i>=n){
        return 0;
    }

    if(dp[i] != -1){
        return dp[i];
    }

    int mini = 1e9;
    for(int j=i+1; j <= min(n,2*(i+1)); j++){
       mini = min(mini, solve(j,n,prices,dp));
    }
    return dp[i]= mini+prices[i];
}
    int minimumCoins(vector<int>& prices) {
        int n=prices.size();
        vector<int>dp(n,-1);
        return solve(0,n,prices,dp);
    }
};