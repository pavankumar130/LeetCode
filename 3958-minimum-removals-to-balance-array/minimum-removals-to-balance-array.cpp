class Solution {
    bool solve(vector<int>&nums, int k, int x){

        int n = nums.size();

        for(int i = 0; i <= x; i++){
            long long maxi = nums[n - 1 - x + i];
            long long mini = nums[i] * (long long)k;

            if(maxi <= mini){
                return true;
            }
        }

        return false;
    }
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        if(nums.back()* 1LL <= k * 1LL * nums[0]){
            return 0;
        }

        int low = 1;
        int high = n - 1;
        int res = n - 1;

        while(low <= high){
            int mid = (low + high) / 2;

            if(solve(nums, k, mid)){
                res = min(res, mid);
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return res;
    }
};