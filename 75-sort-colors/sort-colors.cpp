class Solution {
public:
    void sortColors(vector<int>& nums) {
        int no0=0;
        int no1=0;
        int no2=0;
        if(nums.size()== 1 || nums.size()== 0){
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                no0++;
            }
            if(nums[i] == 1){
                no1++;
            }
            if(nums[i] == 2){
                no2++;
            }
        }
        for(int i=0;i<(no0);i++){
            nums[i]=0;
        }
        for(int i=no0;i<(no0+no1);i++){
            nums[i]=1;
        }
        for(int i=(no0+no1);i<(no0+no1+no2);i++){
            nums[i]=2;
        }
    }
};