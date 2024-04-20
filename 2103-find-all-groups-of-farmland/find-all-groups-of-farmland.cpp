class Solution {
public:
    vector<int>dr{0, 0, 1, -1};
    vector<int>dc{1, -1, 0, 0};
    vector<vector<int>>ans;

    void solve(int i, int j, vector<vector<int>>& land, int &r, int &c, int n, int m){
        if(i < 0 || j < 0 || i >= n || j >= m || land[i][j] == 0 || land[i][j] == 2){
            return;
        }

        land[i][j] = 2;
        r = max(r, i);
        c = max(c, j);

        for(int ind = 0; ind < 4; ind++){
            solve(i + dr[ind], j + dc[ind], land, r, c, n, m);
        }

    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(land[i][j] == 1){
                    int r = 0, c = 0;
                    solve(i, j, land, r, c, n, m);
                    vector<int>temp{i, j, r, c};
                    ans.push_back(temp);
                }
            }
        }

        return ans;
    }
};