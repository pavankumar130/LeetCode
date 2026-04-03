class Solution {
    int countwalls(vector<int>&walls, int l, int r){
        int left = lower_bound(walls.begin(), walls.end(), l) - walls.begin();
        int right = upper_bound(walls.begin(), walls.end(), r) - walls.begin();

        return (right - left);
    }

    int solve(vector<int>&walls, vector<pair<int,int>>&rd, vector<pair<int,int>>&range, int i, int prevdir, vector<vector<int>>&dp){
        if(i == rd.size()){
            return 0;
        }

        if(dp[i][prevdir] != -1){
            return dp[i][prevdir];
        }

        int left = range[i].first;
        if(prevdir == 1){
            left = max(left, range[i - 1].second + 1);
        }

        int left_take = countwalls(walls, left, rd[i].first) + solve(walls, rd, range, i + 1, 0, dp);

        int right_take = countwalls(walls, rd[i].first, range[i].second) + 
                                                    solve(walls, rd, range, i + 1, 1, dp);

        return dp[i][prevdir] = max(left_take, right_take);
    }
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        vector<vector<int>>dp(n, vector<int>(2, -1));
        vector<pair<int,int>>rd(n);
        for(int i = 0; i < n; i++){
            rd[i] = {robots[i], distance[i]};
        }

        sort(rd.begin(), rd.end());
        sort(walls.begin(), walls.end());

        // prepare range vector of each robot
        vector<pair<int,int>>range(n);
        for(int i = 0; i < n; i++){
            int pos = rd[i].first;
            int dis = rd[i].second;

            int left = (i == 0) ? 1 : rd[i - 1].first + 1;
            int right = (i == n - 1) ? 1e9 : rd[i + 1].first - 1;

            int L = max(pos - dis, left);
            int R = min(pos + dis, right);
            range[i] = {L, R};
        }
        // prev = 0/  if robbot hit to left/right
        return solve(walls, rd, range, 0, 0, dp);
    }
};