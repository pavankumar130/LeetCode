class Solution {
public:
int mod=1e9+7;
int solve(int n, int ind, char prev, unordered_map<char,vector<char>>&mp,vector<vector<long long>>&dp){
    if(ind>n){
        return 0;
    }
    if(ind == n){
        return mp[prev].size();
    }

    if(dp[ind][prev-'a'] != -1){
       return dp[ind][prev-'a'];
    }
    long long ans=0;
    for(auto it:mp[prev]){
        ans+= solve(n,ind+1,it,mp,dp);
    }
    return dp[ind][prev-'a'] = ans%mod;
}
    int countVowelPermutation(int n) {
        unordered_map<char,vector<char>>mp;
        mp['c']={'a','e','i','o','u'};
        mp['a']={'e'};
        mp['e']={'a','i'};
        mp['i']={'a','e','o','u'};
        mp['o']={'i','u'};
        mp['u']={'a'};
       vector<vector<long long>>dp(n+2,vector<long long>(27,-1));
        return solve(n,1,'c',mp,dp);
    }
};