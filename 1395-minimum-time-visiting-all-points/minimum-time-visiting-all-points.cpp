class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int count = 0;

        for(int i = 1; i < n; i++){
            int x1 = points[i-1][0];
            int y1 = points[i-1][1];

            int x2 = points[i][0];
            int y2 = points[i][1];

            int increasex1 = abs(x1 - x2);
            int increasey1 = abs(y1 - y2);
            
            int mini = min(increasex1, increasey1);
            int maxi = max(increasex1, increasey1);

            count += (mini) + (maxi - mini);
        }
        
        return count;
    }
};