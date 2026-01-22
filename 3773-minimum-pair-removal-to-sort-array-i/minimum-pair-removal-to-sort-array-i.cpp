class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int cnt = 0;

        while(!is_sorted(nums.begin(), nums.end())){
            cnt++;

            int mini = 1e9;
            int ind = 0;

            for(int i = 0; i < nums.size() - 1; i++){
                if(mini > nums[i] + nums[i + 1]){
                    mini = nums[i] + nums[i + 1];
                    ind = i;
                }
            }

            vector<int>arr;
            for(int i = 0; i < nums.size(); i++){
                if(ind == i){
                    arr.push_back(mini);
                    i++;
                }
                else{
                    arr.push_back(nums[i]);
                }
            }

            nums = arr;
        }

        return cnt;
    }
};