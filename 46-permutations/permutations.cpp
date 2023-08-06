class Solution {
public:
void solve(vector<int>&temp, vector<int>&nums, vector<int>&vis, vector<vector<int>>&ans){
  if(temp.size() == nums.size()){
      ans.push_back(temp);
      return;
  }
  for(int i=0;i<nums.size();i++){
      if(!vis[i]){
          vis[i]=1;
          temp.push_back(nums[i]);
          solve(temp,nums,vis,ans);
          vis[i]=0;
          temp.pop_back();
      }
  }
}
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>temp;
        vector<int>vis(n ,0);
        solve(temp,nums,vis,ans);
        return ans;
    }
};