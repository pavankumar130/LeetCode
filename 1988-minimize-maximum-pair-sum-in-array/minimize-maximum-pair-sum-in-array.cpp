class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int low = 0;
        int high = n - 1;
        int res = 0;

        while(low <= high){
            int sum = nums[low] + nums[high];
            res = max(res, sum);
            low++;
            high--;
        }

        return res;
    }
};