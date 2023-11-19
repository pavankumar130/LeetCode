class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());

        int n=nums.size();
        int ans=0;

        for(int i=1; i<n; i++){
            if(nums[i] != nums[i-1]){
              ans+=(n-i);
            }
        }
        return ans;
    }
};