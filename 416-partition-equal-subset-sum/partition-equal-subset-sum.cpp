class Solution {
public:
bool solve(int ind, int target, vector<int>&nums, vector<vector<int>>&dp, int n){
    if(target == 0){
        return true;
    }
    if(ind == n){
        return target == 0;
    }
    if(dp[ind][target] != -1){
        return dp[ind][target] == 1;
    }

    bool np=solve(ind+1,target,nums,dp,n);

    bool p=false;
    if(target >= nums[ind]){
        p=solve(ind+1, target-nums[ind],nums,dp,n);
    }

    return dp[ind][target] = p||np;
}
bool help(int n, int k, vector<int>&nums){
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    return solve(0,k,nums,dp,n);
}
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }

        if(sum % 2){
            return false;
        }
        int k=sum/2;
        return help(n,k,nums);
    }
};