class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int low = x;
        int high = x + k - 1;

        while(low <= high){
            for(int i = y; i < y + k; i++){
                swap(grid[low][i], grid[high][i]);
            }

            low++;
            high--;
        }

        return grid;
    }
};