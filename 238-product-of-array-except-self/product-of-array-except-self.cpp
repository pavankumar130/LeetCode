class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
      int n=nums.size();
      vector<int>res(n);
      for(int i=0;i<n;i++){
        if(i>0){
          res[i]=nums[i]*res[i-1];
        }
        else{
          res[i]=nums[i];
        }
      }
      int product=1;
      for(int i=n-1;i>=0;i--){
          if(i == 0){
            res[i]=product;
          }
          else{
            res[i]=res[i-1]*product;
          }
          product*=nums[i];
      }
    return res;
  }
};