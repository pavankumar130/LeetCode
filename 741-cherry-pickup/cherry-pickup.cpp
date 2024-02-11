class Solution {
    int solve(int i1, int j1, int i2, int j2, vector<vector<int>>& grid, int n, vector<vector<vector<vector<int>>>>&dp){
        if(i1 >=n || i2 >= n || j1 >= n || j2 >= n || grid[i1][j1] == -1 || grid[i2][j2] == -1){
            return -1e8;
        }

        if(i1 == n-1 && j1 == n-1){
            return grid[i1][j1];
        }

        if(dp[i1][j1][i2][j2] != -1){
            return dp[i1][j1][i2][j2];
        }

        int res = 0;
        if(i1 == i2 && j1 == j2){
            res += grid[i1][j1];
        }
        else{
            res += (grid[i1][j1] + grid[i2][j2]);
        }

        int r = solve(i1+1, j1, i2, j2+1, grid, n, dp);
        int s = solve(i1, j1+1, i2+1, j2, grid, n, dp);
        int t = solve(i1+1, j1, i2+1, j2, grid, n, dp);
        int u = solve(i1, j1+1, i2, j2+1, grid, n, dp);

        int v = max(r,s);
        int w = max(t,u);

        return dp[i1][j1][i2][j2] = (res + max(v,w));
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<vector<int>>>>dp(n,vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(n,-1))));
        int val = solve(0, 0, 0, 0, grid, n, dp);
        if(val <= 0){
            return 0;
        }
        return val;
    }
};