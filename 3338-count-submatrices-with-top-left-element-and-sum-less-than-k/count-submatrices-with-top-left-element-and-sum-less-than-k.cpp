class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>mat = grid;

        for(int i = 0; i < n; i++){
            for(int j = 1; j < m; j++){
                mat[i][j] += mat[i][j-1];
            }
        }

        int cnt = 0;

        for(int j = 0; j < m; j++){
            int sum = 0;
            for(int i = 0; i < n; i++){
                sum += mat[i][j];
                if(sum <= k){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};