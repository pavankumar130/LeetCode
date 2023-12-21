class Solution {
public:
int solve(int i, vector<int>&arr, int k ,int n,vector<int>&dp){
    if(i>=n){
        return 0;
    }

    if(dp[i] != -1){
        return dp[i];
    }

    int maxi = -1;
    int res = -1;
    int len = 0;

    for(int ind = i; ind < min(n,i+k); ind++){
        len++;
        maxi = max(maxi,arr[ind]);
        int sum = (len*maxi)+solve(ind+1,arr,k,n,dp);
        if(res < sum){
            res = sum;
        }
    }

    return dp[i] = res;
}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        int n=arr.size();
        vector<int>dp(n,-1);
        return solve(0,arr,k,n,dp);
    }
};