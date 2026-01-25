class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int sum = 0;
        int i = 0;

        while(i < n){
            sum += nums[i];
            i += 2;
        }

        return sum;
    }
};