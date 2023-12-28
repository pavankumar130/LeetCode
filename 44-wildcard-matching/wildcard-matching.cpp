class Solution {
    bool solve(int i, int j, string &s, string &p,vector<vector<int>>&dp) {
        if (i == 0 && j == 0) {
            return (s[i] == p[j] || p[j] == '?' || p[j] == '*');
        }

        if (i >= 0 && j < 0) {
            return false;
        }

        if (i < 0) {
            if (j >= 0) {
                for (int ind = j; ind >= 0; ind--) {
                    if (p[ind] != '*') {
                        return false;
                    }
                }
                return true;
            }
            return false;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if (s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = solve(i - 1, j - 1, s, p,dp);
        } else if (p[j] == '*') {
            return dp[i][j] = solve(i, j - 1, s, p, dp) || solve(i - 1, j, s, p, dp) || 
                                                         solve(i - 1, j - 1, s, p, dp);
        }

        return false;
    }

public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        if(n == 0 && m == 0){
            return true;
        }
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(n - 1, m - 1, s, p ,dp);
    }
};
