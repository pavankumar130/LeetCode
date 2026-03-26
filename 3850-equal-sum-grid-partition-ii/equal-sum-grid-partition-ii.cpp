class Solution {
    long long totalsum = 0;
    bool Horizontalcut(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        unordered_set<long long>st;
        long long top = 0;
        for(int i = 0; i <= m - 2; i++){
            for(int j = 0; j < n; j++){
                st.insert(grid[i][j]);
                top += grid[i][j];
            }

            long long bottom = totalsum - top;
            long long diff = top - bottom;
            if(diff == 0) return true;

            if(diff == (long long)grid[0][0]) return true;
            if(diff == (long long)grid[0][n - 1]) return true;
            if(diff == (long long)grid[i][0]) return true;

            if(i > 0 && n > 1 && st.count(diff)) return true;
        }

        return false;
    }
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                totalsum += grid[i][j];
            }
        }
        // Horizontal Cut Check.
        if(Horizontalcut(grid)){
            return true;
        }
        reverse(grid.begin(), grid.end());
        if(Horizontalcut(grid)){
            return true;
        }

        reverse(grid.begin(), grid.end()); // again converting to original

        // Vertical Cut Check using Horizontalcut function

        // Transponse original grid
        vector<vector<int>>transpose(n, vector<int>(m));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                transpose[j][i] = grid[i][j];
            }
        }

        if(Horizontalcut(transpose)){
            return true;
        }
        reverse(transpose.begin(), transpose.end());
        if(Horizontalcut(transpose)){
            return true;
        }

        return false;
    }
};