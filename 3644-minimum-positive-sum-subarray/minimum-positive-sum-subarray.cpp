class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int mini = 1e9;

        for(int i = 0; i < nums.size(); i++){
            int sum = 0;
            for(int j = i; j < nums.size(); j++){
                sum += nums[j];

                if( (j - i + 1) >= l && (j - i + 1) <= r && sum > 0){
                    mini = min(mini, sum);
                }
            }
        }

        if(mini == 1e9){
            return -1;
        }
        return mini;
    }
};