class Solution {
public:
bool palindrome(int start, int end, string &s){
    while(start <= end){
        if(s[start] != s[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}
int solve(int ind, string &s,vector<int>&dp){
    if(ind == s.length()){
        return 0;
    }

    if(dp[ind] != -1){
        return dp[ind];
    }
    int mini = 1e9;
    for(int i=ind; i<s.length(); i++){
        if(palindrome(ind,i,s)){
           mini =min(mini, 1+solve(i+1,s,dp));
        }
    }
    return dp[ind]= mini;
}
    int minCut(string s) {
        int n=s.length();
        vector<int>dp(n,-1);
        return solve(0,s,dp)-1;
    }
};