class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int res = INT_MAX;

        int sum = nums[0];
        for(int i = 1; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if((nums[0] + nums[i] + nums[j]) < res){
                    res = (nums[0] + nums[i] + nums[j]);
                }
            }
        }

        return res;
    }
};