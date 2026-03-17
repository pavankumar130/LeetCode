class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        vector<vector<int>>mat = matrix;
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;

        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                if(matrix[row][col] && row > 0){
                    matrix[row][col] += matrix[row - 1][col];
                }
            }

            vector<int>currrow = matrix[row];
            sort(currrow.begin(), currrow.end(), greater());
            for(int i = 0; i < n; i++){
                res = max(res, currrow[i] * (i + 1));
            }
        }

        return res;
    }
};