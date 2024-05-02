class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n = nums.size();
        int maxi = -1;

        for(int i = 0; i < n; i++){
            int num = nums[i];
            if(num < 0){
                continue;
            }

            for(int j = 0; j < n; j++){
                if(nums[j] == -num){
                    maxi = max(maxi, num);
                }
            }
        }

        return maxi;
    }
};