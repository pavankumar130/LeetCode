class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int>mp;
        vector<int>win,los;

        for(int i = 0; i < matches.size() ; i++){
            int l = matches[i][1];
            mp[l]++;
        }

        for(int i = 0; i < matches.size(); i++){
            int w = matches[i][0];
            int l = matches[i][1];

            if(mp.find(w) == mp.end()){
                win.push_back(w);
                mp[w] = 2;
            }
            if( mp[l] == 1 ){
                los.push_back(l);
            }
        }

        sort(win.begin(),win.end());
        sort(los.begin(),los.end());

        return {win,los};
    }
};