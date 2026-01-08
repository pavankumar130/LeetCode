class Solution {
    int solve(vector<int>& nums1, vector<int>& nums2, int n, int m, int i, int j, vector<vector<int>>&dp){
        if(i == n || j == m){
            return -1e9;
        }

        if(dp[i][j] != -1e9){
            return dp[i][j];
        }

        int val = nums1[i] * nums2[j];
        int take = nums1[i] * nums2[j] + solve(nums1, nums2, n, m, i+1, j+1, dp);
        int skip_i = solve(nums1, nums2, n, m, i+1, j, dp);
        int skip_j = solve(nums1, nums2, n, m, i, j+1, dp);

        return dp[i][j] = max({val, take, skip_i, skip_j});
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>>dp(n, vector<int>(m, -1e9));
        return solve(nums1, nums2, n, m, 0, 0, dp);
    }
};