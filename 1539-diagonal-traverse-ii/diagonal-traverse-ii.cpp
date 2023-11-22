class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        queue<pair<int,int>>q;
        q.push({0,0});

        vector<int>arr;

        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            arr.push_back(nums[i][j]);

            if(j == 0 && i+1 < nums.size()){
                q.push({i+1,j});
            }
            if(j+1 < nums[i].size()){
                q.push({i,j+1});
            }
        }
        return arr;
    }
};