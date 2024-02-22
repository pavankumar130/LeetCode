class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<pair<int,int>>temp(n+1);

        for(int i = 0; i < trust.size(); i++){
            int a = trust[i][0];
            int b = trust[i][1];

            temp[a].first++;
            temp[b].second++;
        }

        for(int i = 1; i <= n; i++){
            if(temp[i].first == 0 && temp[i].second == n-1){
                return i;
            }
        }
        return -1;
    }
};