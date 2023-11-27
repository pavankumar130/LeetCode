class Solution {
public:
int mod = 1e9+7;
long long solve(int r, int c, int count,vector<vector<vector<long long>>>&dp){
    if( r < 0 || r >= 4 || c < 0 || c >= 3 || (r == 3 && c == 0) || (r == 3 && c == 2)){
        return 0;
    }
    if(count == 0){
        return 1;
    }
    if(dp[r][c][count] != -1){
        return dp[r][c][count];
    }
    long long res = (solve(r-2,c-1,count-1,dp)%mod+
           solve(r-2,c+1,count-1,dp)%mod+
           solve(r-1,c+2,count-1,dp)%mod+
           solve(r+1,c+2,count-1,dp)%mod+
           solve(r+2,c-1,count-1,dp)%mod+
           solve(r+2,c+1,count-1,dp)%mod+
           solve(r-1,c-2,count-1,dp)%mod+
           solve(r+1,c-2,count-1,dp)%mod)%mod;
    
    dp[r][c][count]=res;
    return res;
}
    int knightDialer(int n) {
        
        int row=4;
        int col=3;
    
vector<vector<vector<long long>>>dp(4,vector<vector<long long>>(3,vector<long long>(n,-1)));

        long long ans = 0;
        for(int i=0; i<4; i++){
            for(int j=0; j<3; j++){
               ans = (ans + solve(i,j,n-1,dp))%mod;
            }
        }
      return (int)ans;
    }
};