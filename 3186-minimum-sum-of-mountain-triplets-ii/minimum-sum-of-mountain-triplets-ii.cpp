class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>nextsmaller(n,0);
        vector<int>prevsmaller(n,0);

        nextsmaller[n-1]=nums[n-1];

        prevsmaller[0]=nums[0];

        for(int i=1; i<n-1; i++){
          prevsmaller[i]=min(prevsmaller[i-1],nums[i]);
          nextsmaller[n-i-1]=min(nextsmaller[n-i], nums[n-i-1]);
        }

        int res=INT_MAX;

        for(int i=1; i<n-1; i++){
            if( prevsmaller[i] < nums[i] && nextsmaller[i] < nums[i] ){
                int num =(prevsmaller[i]+nextsmaller[i]+nums[i]);
                if(res > num){
                    res=num;
                }
            }
        }

        if(res == INT_MAX){
            return -1;
        }
        return res;
    }
};