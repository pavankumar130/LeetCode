class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int>mp;
        set<int>win,los;
        for(int i = 0; i < matches.size() ; i++){
            int w = matches[i][0];
            int l = matches[i][1];
            mp[l]++;
        }

        for(int i = 0; i < matches.size(); i++){
            int w = matches[i][0];
            int l = matches[i][1];

            if(mp.find(w) == mp.end()){
                win.insert(w);
            }
            if( mp[l] == 1 ){
                los.insert(l);
            }
        }

        vector<int>winner,loser;

        for(auto it:win){
            winner.push_back(it);
        }
        for(auto it:los){
            loser.push_back(it);
        }

        return {winner,loser};
    }
};