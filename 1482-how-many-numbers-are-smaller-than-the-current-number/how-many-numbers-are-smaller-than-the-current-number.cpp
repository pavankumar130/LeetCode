class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n,0);

        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(nums[i] > nums[j] && i != j){
                    cnt++;
                }
            }
            res[i] = cnt;
        }
        return res;
    }
};