class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        map<int, int>mp;

        for(auto it: nums){
            if(it < k){
                return -1;
            }
            if(it == k){
                continue;
            }
            mp[it]++;
        }

        return mp.size();
    }
};