class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int res = 1;
        int n = nums.size();
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] < nums[i+1]){
                bool flag = true;
                for(int j = i+1; j < nums.size(); j++){
                    if(nums[j -1 ] < nums[j]){
                        continue;
                    }
                    else{
                        res = max(res, j - i);
                        flag = false;
                        break;
                    }
                }

                if(flag){
                    res = max(res, n - i);
                }
            }
            else if(nums[i] > nums[i+1]){
                bool flag = true;
                for(int j = i+1; j < nums.size(); j++){
                    if(nums[j -1 ] > nums[j]){
                        continue;
                    }
                    else{
                        res = max(res, j - i);
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    res = max(res, n - i);
                }
            }
        }

        return res;
    }
};