class Solution {

    int solve(int ind, vector<vector<int>>&arr, vector<int>&start, int n,vector<int>&dp){
        if(ind >= n){
            return 0;
        }

        if(dp[ind] != -1){
            return dp[ind];
        }

        int idx = lower_bound(start.begin(),start.end(),arr[ind][1]) - start.begin();
        int pick = arr[ind][2] + solve(idx,arr,start,n,dp);
        int notpick = solve(ind+1,arr,start,n,dp);

        return dp[ind] = max(pick,notpick);
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

        int n = startTime.size();

        vector<vector<int>>arr;
        for(int i=0; i<n; i++){
            arr.push_back({startTime[i],endTime[i],profit[i]});
        }

        sort(arr.begin(),arr.end());
        sort(startTime.begin(),startTime.end());

        vector<int>dp(n,-1);
        return solve(0,arr,startTime,n,dp);
    }
};