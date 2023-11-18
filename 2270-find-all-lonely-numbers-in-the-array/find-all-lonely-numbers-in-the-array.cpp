class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        int n=nums.size();
        if(n <= 1){
            return nums;
        }
        vector<int>res;
       sort(nums.begin(),nums.end());
        if( abs(nums[0] - nums[1]) > 1 ){
            res.push_back(nums[0]);
        }
        if( abs(nums[n-1] - nums[n-2]) > 1 ){
            res.push_back(nums[n-1]);
        }

        for(int i=1; i<n-1; i++){
            if( abs(nums[i] - nums[i-1]) > 1){
                if(abs(nums[i] - nums[i+1]) > 1){
                    res.push_back(nums[i]);
                }
            }
        }
        return res;
    }
};