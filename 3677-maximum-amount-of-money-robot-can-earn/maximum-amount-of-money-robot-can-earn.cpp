class Solution {
    vector<int>row = {0, 1};
    vector<int>col = {1, 0};
    int solve(int i, int j, vector<vector<int>>& coins, int m, int n, int robber, vector<vector<vector<int>>>&dp){
        if(i >= m || j >= n){
            return -1e9;
        }
        if(i == m - 1 && j == n - 1){
            if(coins[i][j] < 0 && robber < 2){
                return 0;
            }
            return coins[i][j];
        }

        if(dp[i][j][robber] != -1e9){
            return dp[i][j][robber];
        }

        int maxi = -1e9;
        for(int ind = 0; ind < 2; ind++){
            int drow = i + row[ind];
            int dcol = j + col[ind];

            maxi = max(maxi, coins[i][j] + solve(drow, dcol, coins, m, n, robber, dp));
            if(robber < 2 && coins[i][j] < 0){
                maxi = max(maxi, solve(drow, dcol, coins, m, n, robber + 1, dp));
                
            }
        }

        return dp[i][j][robber] = maxi;
    }
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        vector<vector<vector<int>>>dp(m, vector<vector<int>>(n, vector<int>(3, -1e9)));
        return solve(0, 0, coins, m, n, 0, dp);
    }
};