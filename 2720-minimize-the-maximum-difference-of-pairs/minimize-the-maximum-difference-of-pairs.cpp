class Solution {
    bool solve(vector<int>& nums, int p, int k, int n){
        int cnt = 0;

        int i = 1;
        while(i < n){
            if((nums[i] - nums[i - 1]) <= k){
                cnt++;
                i += 2;
            }
            else{
                i += 1;
            }
        }

        return (cnt >= p);
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int low = 0;
        int high = nums[n - 1];
        int res = 0;

        while(low <= high){
            int mid = (low + high) / 2;
            if(solve(nums, p, mid, n)){
                res = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return res;
    }
};