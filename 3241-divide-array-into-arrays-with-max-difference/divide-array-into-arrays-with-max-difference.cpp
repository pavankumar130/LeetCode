class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        for(int i=0; i<=n-3; i+=3){
            if(nums[i+1]-nums[i] <= k && nums[i+2]-nums[i+1] <= k && nums[i+2]-nums[i] <= k ){
                vector<int>temp ={nums[i],nums[i+1],nums[i+2]};
                res.push_back(temp);
            }
            else{
                return {};
            }
        }
        return res;
    }
};