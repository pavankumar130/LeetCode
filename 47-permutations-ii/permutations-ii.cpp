class Solution {
    void solve(int ind, vector<int>&nums, set<vector<int>>&st){
        if(ind == nums.size() - 1){
            st.insert(nums);
            return;
        }

        for(int i = ind; i < nums.size(); i++){
            swap(nums[i], nums[ind]);
            solve(ind+1, nums, st);
            swap(nums[i], nums[ind]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>>temp;
        solve(0,nums,temp);

        vector<vector<int>>res;
        for(auto it: temp){
            res.push_back(it);
        }

        return res;
    }
};