class Solution {
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        int n = image.size(), m = image[0].size();
        vector<vector<vector<int>>>grid(n, vector<vector<int>>(m));

        for(int i = 0; i < n-2; i++){
            for(int j = 0; j < m-2; j++){
                int sum = 0; bool flag = true;

                for(int k = i; k < i+3; k++){
                    for(int l = j; l < j+3; l++){
                        sum += image[k][l];
                        if(k > i && abs(image[k][l] - image[k-1][l]) > threshold){
                            flag = false;
                            break;
                        }
                        if(l > j && abs(image[k][l] - image[k][l-1]) > threshold){
                            flag = false;
                            break;
                        }
                    }
                }

                if(flag){
                    for(int k = i; k < i+3; k++){
                        for(int l = j; l < j+3; l++){
                            grid[k][l].push_back(sum/9);
                        }
                    }
                }
            }
        }

        vector<vector<int>>res(n,vector<int>(m));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j].size()){
                    int sum = 0;
                    for(auto it:grid[i][j]){
                        sum += it;
                    }

                    res[i][j] = sum / grid[i][j].size();
                }
                else{
                    res[i][j] = image[i][j];
                }
            }
        }

        return res;
    }
};