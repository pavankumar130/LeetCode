class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        
        long long prefix =0;
        int size = nums.size(),res = 0, id = 0;

        for(long long t=1; t<=n; t++){
            if(id < size && nums[id] <= t){
                prefix+=nums[id];
                id++;
            }
            else{
                if(prefix >= t){
                    t = prefix;
                    continue;
                }
                prefix+=t;
                res++;
            }
        }
        return res;
    }
};