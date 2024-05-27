class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        
        int num = n;

        while(num >= 0){
            int cnt = 0;
            for(int i = 0; i < n; i++){
                if(nums[i] >= num){
                    cnt++;
                }
            }

            if(num == cnt){
                return num;
            }
            num--;
        }

        return -1;
    }
};