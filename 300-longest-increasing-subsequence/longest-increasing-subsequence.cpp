class Solution {
    int solve(int ind, int prev, vector<int>&nums,vector<vector<int>>&dp){
        if(ind >= nums.size()){
            return 0;
        }

        if(dp[ind][prev+1] != -1){
            return dp[ind][prev+1];
        }

        if(prev == -1 || nums[prev] < nums[ind]){
            return dp[ind][prev+1] = max(1 + solve(ind+1, ind, nums,dp),solve(ind+1,prev,nums,dp));
        }

        return dp[ind][prev+1] = solve(ind+1,prev,nums,dp);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,-1,nums,dp);
    }
};