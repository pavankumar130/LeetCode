class Solution {
public:
void solve(vector<int>temp,vector<vector<int>>&res,vector<int>&dp,vector<int>& nums){
    if(temp.size() == nums.size()){
        res.push_back(temp);
        return;
    }
    for(int i=0;i<nums.size();i++){
        if(!dp[i]){
            dp[i]=1;
            temp.push_back(nums[i]);
            solve(temp,res,dp,nums);
            dp[i]=0;
            temp.pop_back();
        }
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        vector<int>temp;
        vector<int>dp(nums.size(),0);
        solve(temp,res,dp,nums);
        return res;
    }
};