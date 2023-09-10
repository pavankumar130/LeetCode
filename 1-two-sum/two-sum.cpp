class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        map<int,int>mp;
        for(int i=0; i<n ;i++){
            int a =nums[i];
            int exist = target -a ;
            if(mp.find(exist) != mp.end()){
                return {mp[exist], i};
            }
            mp[a]=i;
        }
        return {};
    }
};