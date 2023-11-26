class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        
        vector<vector<int>>temp(matrix.size());

        for(int j=0; j<matrix[0].size(); j++){
            int dp=0;

            for(int i=0; i<matrix.size(); i++){
                if(matrix[i][j] == 0){
                    dp=0;
                }
                else{
                    dp++;
                }
                temp[i].push_back(dp);
            }

        }

        int res=0;

        for(int i=0; i<temp.size(); i++){
            sort(temp[i].begin(),temp[i].end(),greater<int>{});
            int row_ans=0;
            for(int j=0; j<temp[i].size(); j++){
                row_ans = max(row_ans, temp[i][j]*(j+1));
            }
            res=max(res,row_ans);
        }
        return res;
    }
};