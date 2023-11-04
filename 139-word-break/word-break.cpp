class Solution {
public:
int solve(int i, string &s, unordered_set<string>&st,vector<int>&dp){
    if(i == s.length()){
        return 1;
    }
    if(dp[i] != -1){
        return dp[i];
    }
     string temp;
    for(int j=i; j<s.length();j++){
        temp+=s[j];
        if(st.find(temp) != st.end()){
            if(solve(j+1,s,st,dp) ){
                return dp[i]= 1;
            }
        }
    }
    return dp[i]= 0;
}
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        for(auto it:wordDict){
            st.insert(it);
        }
        vector<int>dp(s.length(),-1);
        return solve(0,s,st,dp);
    }
};