class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
  
        int maxi = nums[n-1];
        int s_maxi = nums[n-2];

        return (maxi-1)*(s_maxi-1);
    }
};