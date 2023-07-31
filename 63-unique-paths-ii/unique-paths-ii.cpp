class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int mod= 1e9*2;
        if(n == 1 && m ==1 && mat[0][0]==1){
            return 0;
        }
        if(mat[0][0] == 1){
            return 0;
        }
      vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i == 0 && j== 0){
                    dp[i][j]=1;
                }
                else{
                    int up=0,left=0;
                    if(i>0 && mat[i][j] != 1){
                        up=dp[i-1][j];
                    }
                    if(j>0 && mat[i][j] != 1){
                        left=dp[i][j-1];
                    }
                    dp[i][j]= (up+left)%mod;
                }
            }
        }
      return dp[n-1][m-1];
    }
};