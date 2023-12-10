class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        unordered_map<int,int>mp;
        int res=0;
        int n=nums.size();
        int i=0, j=0;

        while(j < n){
            mp[nums[j]]++;

            while(mp[nums[j]] > k){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            res = max(res, j-i+1);
            j++;
        }
        return res;
    }
};