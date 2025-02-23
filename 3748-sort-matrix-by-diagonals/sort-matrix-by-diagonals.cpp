class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        map<int, vector<int>>mp;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                mp[(i - j)].push_back(grid[i][j]);
            }
        }

        for(auto it: mp){
            int row, col, ind = 0;
            if(it.first < 0){
                row = 0;
                col = abs(it.first);
                sort(it.second.begin(), it.second.end());
            }
            else{
                col = 0;
                row = abs(it.first);
                sort(it.second.begin(), it.second.end());
                reverse(it.second.begin(), it.second.end());
            }

            while(row < n && col < n){
                grid[row][col] = it.second[ind];
                ind++;
                row++;
                col++;
            }
        }

        return grid;
    }
};