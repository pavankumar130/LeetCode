class Solution {
    bool isvalid(int i, int j, string &s){
         string str = s.substr(i,2);

        if( stoi(str) > 26 || stoi(str) < 10){
            return false;
        }
        return true;
    }
    int solve(map<int,char>&mp, string &s, int ind,vector<int>&dp){
        if(s[ind] == '0'){
            return 0;
        }
         if(ind >= s.size()){
             return 1;
         }
         
         if(dp[ind] != -1){
             return dp[ind];
         }

         int pick1 = solve(mp,s,ind+1,dp);
         int pick2 = 0;
         if( isvalid(ind, ind+1, s) ){
            pick2 = solve(mp,s,ind+2,dp);
         }
        return dp[ind]= (pick1+pick2);
    }
public:
    int numDecodings(string s) {
        if(s[0] == '0'){
            return 0;
        }
        map<int,char>mp;

        for(int i=1; i<=26; i++){
            mp[i] = i-1+'a';
        }
        vector<int>dp(s.length()+1,-1);
        return solve(mp,s,0,dp);
    }
};