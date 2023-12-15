class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        
        int n=paths.size();
        
        unordered_set<string>vis;
        for(int i=0; i<n; i++){
            vis.insert(paths[i][0]);
        }

        for(int i=0; i<n; i++){
            string res=paths[i][1];
            if(vis.find(res) == vis.end()){
                return res;
            }
        }
        return "";
    }
};