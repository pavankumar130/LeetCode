class Solution {
    int n;
    vector<int>bit;

    void update(int val, int id){
        while(id <= n){
            bit[id] += val;

            id += (id & - id);
        }
    }

    int query(int id){
        int res = 0;
        while(id > 0){
            res += bit[id];
            id -= (id & -id);
        }
        return res;
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        n = nums.size();
        bit = vector<int>(n+1, 0);

        vector<pair<int,int>>arr;

        for(int i = 0; i < nums.size(); i++){
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(),arr.end());

        vector<int>res(n,0);

        for(auto it: arr){
            update(1, it.second + 1);
            res[it.second] = query(n) - query(it.second + 1);
        }

        return res;
    }
};