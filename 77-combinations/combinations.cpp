class Solution {
public:
void solve(vector<int>temp,vector<vector<int>>&res, vector<int>&dp,int n, int k, int ind){
    if(temp.size() == k){
        res.push_back(temp);
        return;
    }
    for(int i=ind;i<=n;i++){
        if(!dp[i-1]){
            temp.push_back(i);
            dp[i-1]=1;
            solve(temp,res,dp,n,k,i);
            temp.pop_back();
            dp[i-1]=0;
        }
    }
}
    vector<vector<int>> combine(int n, int k) {
        vector<int>dp(n,0);
        vector<vector<int>>res;
        vector<int>temp;
        solve(temp,res,dp,n,k,1);
        // sort(res.begin(),res.end());
        return res;
    }
};