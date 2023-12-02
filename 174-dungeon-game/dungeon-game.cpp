class Solution {
public:
int solve(int i, int j, int n, int m, vector<vector<int>>&dungeon,vector<vector<int>>&dp){
    if( i>= n || j >= m){
        return 1e9;
    }
    if( i == n-1 && j == m-1){
        if(dungeon[i][j] > 0){
            return 1;
        }
        return 1-dungeon[i][j];
    }
    
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int down = solve(i+1,j,n,m,dungeon,dp);
    int right = solve(i, j+1, n, m, dungeon,dp);

    int res = min(down,right)- dungeon[i][j];
    if(res > 0){
        return dp[i][j] = res;
    }
    return dp[i][j] = 1;
}
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size();
        int m=dungeon[0].size();
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(0,0,n,m,dungeon,dp);
    }
};