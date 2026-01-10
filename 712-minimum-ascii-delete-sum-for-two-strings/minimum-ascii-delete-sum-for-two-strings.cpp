class Solution {
    int solve(string &s1, string &s2, int i, int j, vector<vector<int>>&dp){
        if(i == s1.size() || j == s2.size()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int sum;
        if(s1[i] == s2[j]){
            sum = s1[i] + solve(s1, s2, i + 1, j + 1, dp);
        }
        else{
            sum = max(solve(s1, s2, i + 1, j, dp), solve(s1, s2, i, j + 1, dp));
        }

        return dp[i][j] = sum;
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        int max_common_sum = solve(s1, s2, 0, 0, dp);

        int total_sum = 0;
        for(int i = 0; i < n; i++){
            total_sum += s1[i];
        }
        for(int i = 0; i < m; i++){
            total_sum += s2[i];
        }

        return (total_sum - 2 * (max_common_sum));
    }
};