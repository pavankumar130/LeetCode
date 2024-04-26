class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        vector<vector<int>>dp(n, vector<int>(m, 0));

        for(int j = 0; j < m; j++){
            dp[0][j] = matrix[0][j];
        }

        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                dp[i][j] = matrix[i][j];

                int prev = INT_MAX;
                for(int k = 0; k < m; k++){
                    if(k != j){
                        prev = min(prev, dp[i-1][k]);
                    }
                }
                dp[i][j] += prev;
            }
        }

        int res = INT_MAX;
        for(int j = 0; j < m; j++){
            res = min(res, dp[n-1][j]);
        }

        return res;
    }
};