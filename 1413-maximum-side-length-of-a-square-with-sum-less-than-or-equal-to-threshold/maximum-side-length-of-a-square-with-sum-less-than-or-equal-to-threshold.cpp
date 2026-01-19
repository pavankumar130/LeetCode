class Solution {
    bool check(vector<vector<int>>& mat, int i, int j, int k, int threshold){
        for(int row = i; row < i + k; row++){
            for(int col = j; col < j + k; col++){
                threshold -= mat[row][col];

                if(threshold < 0){
                    return false;
                }
            }
        }

        return true;
    }
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        // optimization - 1.
        int n = mat.size();
        int m = mat[0].size();

        int low = 0;
        int high = min(m, n);

        while(low <= high){
            int mid = (low + high) / 2;
            bool found = false;

            for(int i = 0; i <= n - mid; i++){
                for(int j = 0; j <= m - mid; j++){
                    if(check(mat, i, j, mid, threshold)){
                        found = true;
                    }
                }
            }

            if(found){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return high;
    }
};