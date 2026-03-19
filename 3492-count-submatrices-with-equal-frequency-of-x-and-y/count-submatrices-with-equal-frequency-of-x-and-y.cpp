class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;

        vector<vector<pair<int,int>>>sum(n, vector<pair<int,int>>(m));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                sum[i][j].first = (grid[i][j] == 'X');
                sum[i][j].second = (grid[i][j] == 'Y');

                if(i - 1 >= 0){
                    sum[i][j].first += sum[i - 1][j].first;
                    sum[i][j].second += sum[i - 1][j].second; 
                }
                if(j - 1 >= 0){
                    sum[i][j].first += sum[i][j - 1].first;
                    sum[i][j].second += sum[i][j - 1].second; 
                }
                if(i - 1 >= 0 && j - 1 >= 0){
                    sum[i][j].first -= sum[i - 1][j - 1].first;
                    sum[i][j].second -= sum[i - 1][j - 1].second; 
                }

                if(sum[i][j].first == sum[i][j].second && sum[i][j].first > 0){
                    res++;
                }
            }
        }
        return res;
    }
};