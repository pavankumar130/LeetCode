class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int n=nums.size();

        for(int i=0; i<n; i++){
            mp[nums[i]] = i;
        }

        for(int i=0; i<n; i++){
           int num = target - nums[i];
           if(mp.find(num) != mp.end() && mp[num] != i){
               return {i,mp[num]};
           }
        }

        return {-1};
    }
};