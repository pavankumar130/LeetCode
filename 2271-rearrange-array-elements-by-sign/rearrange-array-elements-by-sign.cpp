class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos,neg;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                pos.push_back(nums[i]);
            }
            else{
                neg.push_back(nums[i]);
            }
        }

        int cnt = 0;
        for(int i = 0; i < n; i+=2){
            nums[i] = pos[cnt];
            cnt++;
        }
        cnt = 0;
        for(int i = 1; i < n; i+=2){
            nums[i] = neg[cnt];
            cnt++;
        }
        return nums;
    }
};