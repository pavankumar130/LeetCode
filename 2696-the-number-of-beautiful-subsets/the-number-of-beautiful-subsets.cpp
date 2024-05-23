class Solution {
    int cnt;
    unordered_map<int, int>vis;

    void solve(vector<int>& nums, int k, int ind){
        if(ind == nums.size()){
            cnt++;
            return;
        }

        int num = nums[ind];

        if(vis.find(num - k) == vis.end() && vis.find(num + k) == vis.end()){

            vis[num]++;
            solve(nums, k, ind + 1);
            vis[num]--;

            if(vis[num] == 0){
                vis.erase(num);
            }
        }

        solve(nums, k, ind + 1);
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        cnt = 0;
        solve(nums, k, 0);
        return cnt - 1;
    }
};