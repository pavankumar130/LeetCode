class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long>degree(n, 0);

        for(int i = 0; i < roads.size(); i++){
            degree[roads[i][0]]++;
            degree[roads[i][1]]++;
        }

        sort(degree.begin(), degree.end());

        long long val = 1;
        long long totalsum = 0;

        for(int i = 0; i < n; i++){
            totalsum += (val * degree[i]);
            val++;
        }

        return totalsum;
    }
};