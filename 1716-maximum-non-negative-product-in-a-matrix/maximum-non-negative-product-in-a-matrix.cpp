class Solution {
public:
using ll = long long;
int mod = 1e9 + 7;
vector<int>drow = {1, 0};
vector<int>dcol = {0, 1};

    pair<ll,ll>solve(int r, int c, vector<vector<int>>& grid, vector<vector<pair<ll,ll>>>&dp){
        int n = grid.size();
        int m = grid[0].size();

        if(r == n - 1 && c == m - 1){
            return make_pair(grid[r][c], grid[r][c]);
        }

        if(dp[r][c] != make_pair(-1e9, -1e9)){
            return dp[r][c];
        }

        ll currval = grid[r][c];
        ll maxi = -1e9;
        ll mini = 1e9;

        for(int i = 0; i < 2; i++){
            int newr = r + drow[i];
            int newc = c + dcol[i];
            if(newr >= 0 && newr < n && newc >= 0 && newc < m){
                pair<ll,ll> nextdata = solve(newr, newc, grid, dp);
                maxi = max({maxi, nextdata.first * currval, nextdata.second * currval});
                mini = min({mini, nextdata.first * currval, nextdata.second * currval});
            }
        }

        return dp[r][c] = {maxi, mini};
    }
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<pair<ll,ll>>>dp(n, vector<pair<ll,ll>>(m, {-1e9, -1e9}));

        pair<ll,ll> res = solve(0, 0, grid, dp);
        if(res.first < 0){
            return -1;
        }
        return (res.first % mod);
    }
};