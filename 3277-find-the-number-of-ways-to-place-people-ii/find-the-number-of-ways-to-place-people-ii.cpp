class Solution {
    static bool cmp(vector<int>&a, vector<int>&b){
        if(a[0] != b[0]){
            return a[0] < b[0];
        }
        return a[1] > b[1];
    }
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int res = 0;
        sort(points.begin(),points.end(),cmp);

        for(int i = 0; i < n; i++){
            int cx = points[i][0], cy = points[i][1];
            int k = INT_MIN;
            for(int j = i+1; j < n; j++){
                int tx = points[j][0], ty = points[j][1];
                if(ty > cy){
                    continue;
                }
                if(ty > k && cy >= ty){
                    res++;
                    k = ty;
                }
            }
        }
        return res;
    }
};