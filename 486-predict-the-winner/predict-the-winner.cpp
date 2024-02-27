class Solution {
    int solve(vector<int>&nums, int i, int j, int choice){
        if(i > j){
            return 0;
        }

        if(choice == 0){
            return max( nums[i] + solve(nums, i+1, j, 1), nums[j] + solve(nums, i, j-1, 1)); 
        }
        return min(solve(nums, i+1, j, 0),  solve(nums, i, j-1, 0)); 
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }

        long long one = (long long)solve(nums,0,n-1,0);
        sum = sum - one;

        return (one >= sum);
    }
};