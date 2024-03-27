class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int  n = nums.size();

        int i = 0, j = 0;
        long long product = 1;
        int cnt = 0;
        while(i < n){
            product *= nums[i++];

            while(j < i && product >= k){
                product /= nums[j];
                j++;
            }

            cnt += (i - j);
        }

        return cnt;
    }
};