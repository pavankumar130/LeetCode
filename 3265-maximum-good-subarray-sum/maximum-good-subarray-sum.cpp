class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,vector<int>>mp;
        vector<long long>sum(n);
        long long res = LONG_MIN;
        
        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
            if(i == 0){
                sum[i] = nums[i];
            }
            else{
                sum[i] = sum[i-1] + nums[i];
            }
        }

        for(int i = 0; i < n; i++){
            int tar = nums[i] + k;

            for(auto it:mp[tar]){
                if(it > i){
                    res = max(res, sum[it] - sum[i] + nums[i]);
                }
            }

            tar = nums[i] - k;

            for(auto it:mp[tar]){
                if(it > i){
                    res = max(res, sum[it] - sum[i] + nums[i]);
                }
            }
        }

        if(res == LONG_MIN){
            return 0;
        }
        return res;
    }
};