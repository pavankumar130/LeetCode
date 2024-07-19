class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>res;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int num = matrix[i][j];
                bool flag = true;

                for(int k = 0; k < n; k++){
                    if(num < matrix[k][j]){
                        flag = false;
                    }
                }

                for(int k = 0; k < m; k++){
                    if(num > matrix[i][k]){
                        flag = false;
                    }
                }

                if(flag)res.push_back(num);
            }
        }

        return res;
    }
};