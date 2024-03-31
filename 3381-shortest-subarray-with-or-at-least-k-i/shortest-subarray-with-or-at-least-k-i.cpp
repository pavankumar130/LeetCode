class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int res = INT_MAX;

        int n = nums.size();

        for(int i = 0; i < n; i++){
            int cnt = 0, xo = 0;
            for(int j = i; j < n; j++){
                cnt++;
                xo |= nums[j];
                cout<<xo<<" ";
                if(xo >= k){
                    res = min(res, cnt);
                }
            }
            cout<<endl;
        }

        if(res == INT_MAX){
            return -1;
        }
        return res;
    }
};