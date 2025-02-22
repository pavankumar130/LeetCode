class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int sum = 0;

        for(int i = 0; i < nums.size(); i++){
            if(i - k >= 0 && i + k < nums.size()){
                if(nums[i] > nums[i - k] && nums[i] > nums[i + k]){
                    sum += nums[i];
                }
                continue;
            }
            if(i - k >= 0){
                if(nums[i] > nums[i - k] ){
                    sum += nums[i];
                }
                continue;
            }
            if( i + k < nums.size()){
                if( nums[i] > nums[i + k]){
                    sum += nums[i];
                }
                continue;
            }
        }

        return sum;
    }
};