class Solution {
    int solve(vector<vector<int>>&grid, int y, int rem){
        int cnt = 0;
        int n = grid.size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j && i <= n/2 && j <= n/2){
                    if(grid[i][j] != y){
                        cnt++;
                    }
                    continue;
                }

                if(i + j == n-1 && i <= n/2 && j >= n/2){
                     if(grid[i][j] != y){
                        cnt++;
                    }
                    continue;
                }

                if(j == n/2 && i >= n/2){
                    if(grid[i][j] != y){
                        cnt++;
                    }
                    continue;
                }

                if(grid[i][j] != rem){
                    cnt++;
                }
            }
        }
        return cnt;
    }
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int mini = min({solve(grid, 0, 1), solve(grid, 0, 2),
                        solve(grid, 1, 0), solve(grid, 1, 2),
                        solve(grid, 2, 0), solve(grid, 2, 1)});
        return mini;
    }
};