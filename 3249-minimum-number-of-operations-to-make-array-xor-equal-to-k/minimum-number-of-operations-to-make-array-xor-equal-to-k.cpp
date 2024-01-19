class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int temp = 0;

        for(int i = 0; i < nums.size(); i++){
            temp^=nums[i];
        }

        int num = k;
        int cnt = 0;
        while(temp | num){
            if(temp%2 != num%2){
                cnt++;
            }
            temp/=2;
            num/=2;
        }
        return cnt;
    }
};