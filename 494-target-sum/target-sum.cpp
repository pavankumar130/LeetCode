class Solution {
public:
    int solve(int ind, int sum, vector<int>&arr, vector<vector<int>>&dp){
        if(ind == 0){
            if(sum == 0 && arr[0] == 0){
                return 2;
            }
            if(sum == 0 || arr[0] == sum){
                return 1;
            }
            return 0;
        }
        if(dp[ind][sum] != -1){
            return dp[ind][sum];
        }

        int np=solve(ind-1,sum,arr,dp);
        int p=0;
        if(arr[ind] <= sum){
            p=solve(ind-1,sum-arr[ind],arr,dp);
        }

        return dp[ind][sum]=(p+np);
    }

    int help(int n, vector<int>&arr, int d){
        vector<vector<int>>dp(n,vector<int>(d+1,-1));
        return solve(n-1,d,arr,dp);
    }

    int countPartitions(int n, int d, vector<int> &arr) {
        // Write your code here.
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }

        if(sum - d <0 || (sum-d)%2){
            return 0;
        }

        return help(n, arr, (sum-d)/2);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return countPartitions(n,target,nums);
    }
};