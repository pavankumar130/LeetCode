class Solution {
    bool check(vector<vector<int>>& prefix, int i, int j, int k, int threshold){
        int n = prefix.size() - 1;
        int m = prefix[0].size() - 1;

        if(i + k > n || j + k > m){
            return false;
        }

        int sum = 0;
        sum += prefix[i + k][j + k];
        sum -= prefix[i + k][j - 1];
        sum -= prefix[i - 1][j + k];
        sum += prefix[i - 1][j - 1];

        return sum <= threshold;
    }
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        // optimization - 2 prefixsum.
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>>prefix(n + 1, vector<int>(m + 1, 0));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                prefix[i][j] = mat[i - 1][j - 1];
                prefix[i][j] += prefix[i - 1][j];
                prefix[i][j] += prefix[i][j -1];
                prefix[i][j] -= prefix[i - 1][j - 1];
            }
        }

        int maxi = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                int low = 0;
                int high = min(m, n);

                while(low <= high){
                    int mid = (low + high) / 2;

                    if(check(prefix, i, j, mid, threshold)){
                        low = mid + 1;
                        maxi = max(maxi, mid + 1);
                    }
                    else{
                        high = mid - 1;
                    }
                }
            }
        }

        return maxi;
    }
};