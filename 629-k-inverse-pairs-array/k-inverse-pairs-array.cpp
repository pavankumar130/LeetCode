// class Solution {
// public:
//     int kInversePairs(int n, int k) {
//         vector<vector<int>>dp(n+1,vector<int>(k+1,1));
//         int mod = 1e9+7;
//         for(int i = 1; i <= n; i++){
//             for(int j = 0; j <= k; j++){
//                 for(int num = 0; num <= min(j,i-1); num++){
//                     dp[i][j] = (dp[i][j] + dp[i-1][j-num])%mod;
//                 }
//             }
//         }
//         return dp[n][k];
//     }
// };
class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        int mod = 1e9 + 7;
        
        dp[0][0] = 1; // Base case
        
        for (int i = 1; i <= n; i++) {
            dp[i][0] = 1; // Base case: k = 0
            for (int j = 1; j <= k; j++) {
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
                if (j >= i) {
                    dp[i][j] = (dp[i][j] - dp[i - 1][j - i] + mod) % mod;
                }
            }
        }
        
        return dp[n][k];
    }
};
