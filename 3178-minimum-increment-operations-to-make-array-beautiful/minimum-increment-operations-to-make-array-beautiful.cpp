class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>dp(n,0);

        for(int i=0; i<n; i++){
           if(i<=2){
             dp[i] = max(0,k-nums[i]);
           }
           else{
               dp[i]= max(0,k-nums[i])+ min(dp[i-1],min(dp[i-2],dp[i-3]));
           } 
        }

        return min(dp[n-1],min(dp[n-2],dp[n-3]));
    }
};