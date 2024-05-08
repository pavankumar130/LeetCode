class Solution {
    static bool cmp(pair<int,int>&a, pair<int,int>&b){
        return a.first > b.first;
    }
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<pair<int, int>>rank;

        for(int i = 0; i < score.size(); i++){
            rank.push_back({score[i], i});
        }

        sort(rank.begin(), rank.end(), cmp);

        vector<string>res(n);
        for(int i = 0; i < rank.size(); i++){
            if(i == 0){
                res[rank[i].second] = "Gold Medal";
            }
            else if(i == 1){
                res[rank[i].second] = "Silver Medal";
            }
            else if(i == 2){
                res[rank[i].second] = "Bronze Medal";
            }
            else{
                res[rank[i].second] = to_string(i+1);
            }
        }

        return res;
    }
};