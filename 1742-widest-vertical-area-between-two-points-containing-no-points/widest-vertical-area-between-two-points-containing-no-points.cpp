class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        
        int n=points.size();
        sort(points.begin(),points.end());
        int maxi = 0;

        for(int i=1; i<n; i++){
            int x1 = points[i][0];
            int x2 = points[i-1][0];

            maxi = max(maxi, x1-x2);
        }
        return maxi;

    }
};