class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long res = 0;
        int n = nums.size();
        int badi = -1, mini = -1, maxi = -1;

        for(int i = 0; i < n; i++){
            if(nums[i] < minK || nums[i] > maxK){
                badi = i;
            }

            if(nums[i] == minK){
                mini = i;
            }

            if(nums[i] == maxK){
                maxi = i;
            }

            res += max(0, min(maxi, mini) - badi);
        }
        return res;
    }
};