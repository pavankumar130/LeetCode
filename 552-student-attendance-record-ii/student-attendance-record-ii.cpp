class Solution {
    int mod = 1e9 + 7;
    int solve(int n, int t_a, int c_l, vector<vector<vector<int>>>&dp){
        if(t_a >= 2 || c_l >= 3){
            return 0;
        }
        if(n == 0){
            return 1;
        }

        if(dp[n][t_a][c_l] != -1){
            return dp[n][t_a][c_l];
        }

        int cnt = 0;
        cnt = solve(n - 1, t_a, 0, dp);
        cnt = (cnt + solve(n - 1, t_a + 1, 0, dp))%mod;
        cnt = (cnt + solve(n - 1, t_a, c_l + 1, dp))%mod;

        return dp[n][t_a][c_l] = cnt;
    }
public:
    int checkRecord(int n) {
        vector<vector<vector<int>>>dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));

        return solve(n , 0, 0, dp);
    }
};