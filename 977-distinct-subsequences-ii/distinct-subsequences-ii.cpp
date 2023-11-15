class Solution {
public:
    int distinctSubseqII(string s) {
        int n=s.length();
        int mod=1e9+7;
        vector<long long>dp(n+1);
        dp[0]=1;

        vector<int>mp(26,-1);

        for(int i=1; i<=n; i++){

            dp[i]=(2*dp[i-1])%mod;

            if(mp[s[i-1]-'a'] != -1){
                dp[i]=(dp[i]- dp[mp[s[i-1]-'a']-1]+ mod)%mod;
            }
            mp[s[i-1]-'a']= i;
        }

        return (dp[n]-1+mod)%mod;
    }
};