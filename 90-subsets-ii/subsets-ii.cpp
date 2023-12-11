class Solution {
public:
void solve(int i, vector<int>&nums,vector<int>&temp, set<vector<int>>&res){
    if(i >= nums.size()){
        res.insert(temp);
        return;
    }
    temp.push_back(nums[i]);
    solve(i+1,nums,temp,res);
    temp.pop_back();
    solve(i+1,nums,temp,res);
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>res;
        vector<int>temp;
        solve(0,nums,temp,res);

        vector<vector<int>>ans;
        for(auto it:res){
            ans.push_back(it);
        }
        return ans;
    }
};