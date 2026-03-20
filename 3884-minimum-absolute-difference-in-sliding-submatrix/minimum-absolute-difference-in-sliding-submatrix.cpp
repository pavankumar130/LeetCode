class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>res(m - k + 1, vector<int>(n - k + 1));

        for(int row = 0; row < m - k + 1; row++){
            for(int col = 0; col < n - k + 1; col++){
                set<int>st;

                for(int i = row; i < row + k; i++){
                    for(int j = col; j < col + k; j++){
                        st.insert(grid[i][j]);
                    }
                }

                if(st.size() > 1){
                    int mini = INT_MAX;
                    auto prev = st.begin();
                    auto curr = next(prev);
                    while(curr != st.end()){
                        mini = min(mini, abs(*prev - *curr));
                        prev = curr;
                        curr ++;
                    }

                    res[row][col] = mini;
                }
                else{
                    res[row][col] = 0;
                }
            }
        }
        return res;
    }
};