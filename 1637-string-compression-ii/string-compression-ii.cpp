int dp[101][27][101][101];
class Solution {
    int solve(string &s, int ind, int prev, int cnt, int k){
        if(k < 0){
            return 1e9;
        }
        if(ind == s.length()){
            return 0;
        }

        if(dp[ind][prev][cnt][k] != -1){
            return dp[ind][prev][cnt][k];
        }

        int del = solve(s,ind+1,prev,cnt,k-1);

        int acc = 0;
        if(s[ind] == prev+'a'){
            acc =solve(s,ind+1,prev,cnt+1,k) + (cnt==1 || cnt == 9 || cnt == 99);
        }
        else{
            acc = 1 + solve(s,ind+1,s[ind]-'a',1,k);
        }

        return dp[ind][prev][cnt][k] = min(acc,del);
    }
public:
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.length();
        memset(dp,-1,sizeof(dp));
        return solve(s,0,26,0,k);
    }
};