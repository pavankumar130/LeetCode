class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long res = 0;
        int n = nums.size();
        int prev = -1;
        for(int i = 0; i < n; i++){
            if( i > 0 && nums[i] == nums[i-1]){
                prev = i - 1;
            }
            res += (i - prev);
        }

        return res;
    }
};