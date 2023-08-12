class Solution {
public:
int solve(int ind, int pre, vector<int>&nums, int n,vector<vector<int>>&dp){
    if(ind == n){
        return 0;
    }
    if(dp[ind][pre+1] != -1){
        return dp[ind][pre+1];
    }
    int np=solve(ind+1,pre,nums,n,dp);
    int p=INT_MIN;
    if(pre == -1 || nums[ind]>nums[pre]){
       p=1+solve(ind+1,ind,nums,n,dp);
    }
    return dp[ind][pre+1] = max(p,np);
}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,-1,nums,n,dp);
    }
};