class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 1; j < m; j++){
                matrix[i][j] += matrix[i][j-1];
            }
        }

        int cnt = 0;

        for(int i = 0; i < m; i++){
            for(int j = i; j < m; j++){
                unordered_map<int,int>mp;
                mp[0] = 1;
                int sum = 0;
                for(int r = 0; r < n; r++){
                    sum += matrix[r][j];
                    if(i > 0){
                        sum -= matrix[r][i-1];
                    }

                    cnt += mp[sum-target];
                    mp[sum]++;
                }
            }
        }
        return cnt;
    }
};