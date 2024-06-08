class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int presum = 0;
        unordered_map<int,int>mp;
        mp[0] = -1;

        for(int i = 0; i < nums.size(); i++){
            presum = (presum + nums[i]) % k;

            if(mp.find(presum) != mp.end()){
                if(i - mp[presum] > 1){
                    return 1;
                }
            }
            else{
                mp[presum] = i;
            }
        }

        return 0;
    }
};