class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_map<int,int>dp;
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            dp[nums[i] + 1] = dp[nums[i]] + 1;
            dp[nums[i]] = dp[nums[i] - 1] + 1;

            res = max(res, max(dp[nums[i] + 1], dp[nums[i]]));
        }
        return res;
    }
};