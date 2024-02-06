class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int res = 0;
        for(int i = 0; i < n; i++){
            int cx = points[i][0], cy = points[i][1];
            for(int j = 0; j < n; j++){
                int tx = points[j][0], ty = points[j][1];
                if(i == j || tx < cx || ty > cy){
                    continue;
                }

                bool flag = true;
                for(int k = 0; k < n; k++){
                    if(i == k || j == k){
                        continue;
                    }

                    if(points[k][0] <= tx && points[k][0] >= cx &&
                       points[k][1] <= cy && points[k][1] >=ty){
                           flag = false;
                           break;
                       }
                }

                if(flag){
                    res++;
                }
            }
        }
        return res;
    }
};