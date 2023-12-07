class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        
        int n=nums.size();

        int i=0;
        int j=0;

        int res = 0;
        int count = 0;

        while(j < n){
            if(nums[j] > right){
                i = j+1;
                count = 0;
            }
            else if(nums[j] < left){
                res+=count;
            }
            else{
                count = (j-i+1);
                res+=count;
            }
          j++;
        }
      return res;
    }
};