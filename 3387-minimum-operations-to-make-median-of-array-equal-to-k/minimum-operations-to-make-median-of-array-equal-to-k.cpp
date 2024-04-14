class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int mid = n / 2;

        if(nums[mid] == k){
            return 0;
        }

        long long cnt = 0;

        if(nums[mid] < k){
            int i = mid;
            while(i < n && nums[i] < k){
                cnt += (k - nums[i++]);
            }
        }
        else if(nums[mid] > k){
            int i = mid;
            while(i >= 0 && nums[i] > k){
                cnt += (nums[i--] - k);
            }
        }

        return cnt;
    }
};