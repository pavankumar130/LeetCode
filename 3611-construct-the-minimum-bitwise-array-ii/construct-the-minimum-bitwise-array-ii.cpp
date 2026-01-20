class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n, -1);

        for(int i = 0; i < n; i++){
            if(nums[i] == 2){
                continue;
            }
            
            int val = nums[i];
            int d = 0;

            while( (val & (1 << d)) != 0){
                d++;
            }

            res[i] = val - (1 << (d - 1));
        }

        return res;
    }
};