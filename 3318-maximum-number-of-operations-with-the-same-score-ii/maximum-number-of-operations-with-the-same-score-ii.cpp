class Solution {
    vector<vector<int>>dp;
    int solve(int l, int r, vector<int>&nums, int tar){
        if(l >= r){
            return 0;
        }

        if(dp[l][r] != -1){
            return dp[l][r];
        }

        int ans = 0;
        if( nums[l] + nums[l + 1] ==  tar){
            ans = max(ans, 1 + solve(l+2, r, nums, tar));
        }

        if( nums[r] + nums[r-1] == tar ){
            ans = max(ans, 1 + solve(l, r-2, nums, tar) );
        }

        if(nums[l] + nums[r] == tar){
            ans = max(ans, 1 + solve(l+1, r-1, nums, tar));
        }

        return dp[l][r] = ans;
    }
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size();

        
        dp = vector<vector<int>>(n, vector<int>(n, -1));
        int opt1 = solve(0, n-1, nums, nums[0] + nums[1]);

        dp = vector<vector<int>>(n, vector<int>(n, -1));
        int opt2 = solve(0, n-1, nums, nums[0] + nums[n-1]);

        dp = vector<vector<int>>(n, vector<int>(n, -1));
        int opt3 =solve(0, n-1, nums, nums[n-2] + nums[n-1]);

        return max(opt1, max(opt2, opt3));
    }
};