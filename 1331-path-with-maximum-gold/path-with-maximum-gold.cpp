class Solution {
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    int maxi = 0;
    int solve(int i, int j, int n, int m, vector<vector<int>>& grid){
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0){
            return 0;
        }

        int curr = grid[i][j];
        grid[i][j] = 0;
        int local = curr;

        for(int ind = 0; ind < 4; ind++){
            int x = i + dr[ind];
            int y = j + dc[ind];
            local = max(local, curr + solve(x, y, n, m, grid));
        }

        grid[i][j] = curr;
        return local;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]){
                    maxi = max(maxi, solve(i, j, n, m, grid));
                }
            }
        }

        return maxi;
    }
};