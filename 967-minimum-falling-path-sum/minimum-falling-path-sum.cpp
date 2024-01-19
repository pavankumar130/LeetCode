class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>>dp(n,vector<int>(m));

        for(int i = 0; i < m; i++){
            dp[0][i] = matrix[0][i];
        }

        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                int d = matrix[i][j] + dp[i-1][j];

                int ld = 1e9, rd = 1e9;
                if(j-1 >= 0){
                    ld = matrix[i][j] + dp[i-1][j-1];
                }
                if(j+1 < m){
                    rd = matrix[i][j] + dp[i-1][j+1];
                }

                dp[i][j] = min(d,min(ld,rd));
            }
        }

        int res = 1e9;
        for(int i = 0; i < m; i++){
            res = min(res, dp[n-1][i]);
        }
        return res;
    }
};