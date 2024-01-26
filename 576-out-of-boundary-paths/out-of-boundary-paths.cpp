class Solution {
    int dp[51][51][51];
    long long mod = 1e9+7;
    int solve(int i, int j, int m, int n, int maxi){
        
        if(i < 0 || i >= m || j < 0 || j >= n){
            return 1;
        }
        if(maxi <= 0){
            return 0;
        }

        if(dp[i][j][maxi] != -1){
            return dp[i][j][maxi];
        }
        
        int up = solve(i-1,j,m,n,maxi-1);
        int down = solve(i+1,j,m,n,maxi-1);
        int left = solve(i,j-1,m,n,maxi-1);
        int right = solve(i,j+1,m,n,maxi-1);

        return dp[i][j][maxi] = (up%mod + down%mod + left%mod + right%mod)%mod;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return solve(startRow,startColumn,m,n,maxMove);
    }
};