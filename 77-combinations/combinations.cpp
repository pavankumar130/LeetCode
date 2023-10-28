class Solution {
public:
void solve(vector<int>temp,vector<vector<int>>&res, vector<int>&dp, vector<int>&arr,int n, int k, int ind){
    if(temp.size() == k){
        res.push_back(temp);
        return;
    }
    for(int i=ind;i<n;i++){
        if(!dp[i]){
            temp.push_back(arr[i]);
            dp[i]=1;
            solve(temp,res,dp,arr,n,k,i);
            temp.pop_back();
            dp[i]=0;
        }
    }
}
    vector<vector<int>> combine(int n, int k) {
        vector<int>arr(n);
        for(int i=1;i<=n;i++){
           arr[i-1]=i;
        }
        vector<int>dp(n,0);
        vector<vector<int>>res;
        vector<int>temp;
        solve(temp,res,dp,arr,n,k,0);
        sort(res.begin(),res.end());
        return res;
    }
};