class Solution {
    bool solve(vector<int>&nums, vector<int>&changeIndicesZero, int mid){
        int n = nums.size();
        vector<int>last(n, -1);

        for(int i = 0; i <= mid; i++){
            last[changeIndicesZero[i]] = i;
        }

        int completed = 0, pow = 0;

        for(int i = 0; i <= mid; i++){
            if(i == last[changeIndicesZero[i]]){
                if(nums[changeIndicesZero[i]] > pow){
                    return false;
                }
                pow -= nums[changeIndicesZero[i]];
                completed++;
            }
            else{
                pow++;
            }
        }

        return completed == n;
    }
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n = nums.size(), m = changeIndices.size();

        vector<int>changeIndicesZero = changeIndices;
        for(auto &it:changeIndicesZero){
            it--;
        }

        int low = 0, high = m - 1, res = -1;

        while(low <= high){
            int mid = (low + high)/2;
            if(solve(nums,changeIndicesZero,mid)){
                res = mid;
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }
        if(res == -1){
            return -1;
        }
        return res + 1;
    }
};