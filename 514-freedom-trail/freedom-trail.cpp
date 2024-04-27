class Solution {
    int help(int curr, int next, int ringlength){
        int stepsBetween = abs(curr - next);
        int stepAround = ringlength - stepsBetween;

        return min(stepsBetween, stepAround);
    }
    int solve(int ringIndex, int keyIndex, string &ring, string &key, int mini, vector<vector<int>>&dp){
        if(keyIndex == key.size()){
            return 0;
        }

        if(dp[ringIndex][keyIndex] != -1){
            return dp[ringIndex][keyIndex];
        }

        for(int i = 0; i < ring.size(); i++){
            if(ring[i] == key[keyIndex]){
                int total = help(ringIndex, i, ring.size()) + 1 + 
                            solve(i, keyIndex + 1, ring, key, INT_MAX, dp);
                mini = min(mini, total);
            }
        }

        return dp[ringIndex][keyIndex] = mini;
    }
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size(), m = key.size();

        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return solve(0, 0, ring, key, INT_MAX, dp);
    }
};