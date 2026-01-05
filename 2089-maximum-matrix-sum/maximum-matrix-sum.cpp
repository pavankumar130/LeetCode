class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long maxsum = 0;
        long long no_of_negative = 0;
        long long mini = 1e9 + 7;

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                maxsum = (maxsum + abs(matrix[i][j]));
                if(matrix[i][j] < 0){
                    no_of_negative++;
                }
                long long val = abs(matrix[i][j]);
                mini = min(mini, val);
            }
        }

        if(no_of_negative % 2 == 0){
            return maxsum;
        }
        // cout<<mini<<" "<<no_of_negative<<" ";
        return (maxsum - (2 * mini));
    }
};