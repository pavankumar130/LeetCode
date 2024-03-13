class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int,vector<int>>mp;

        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[i].size(); j++){
                mp[i + j].push_back(mat[i][j]);
            }
        }

        vector<int>res;

        for(auto it:mp){
            vector<int>v;
            for(int i = 0; i < it.second.size(); i++){
                v.push_back(it.second[i]);
            }

            if(it.first %2 == 0){
                reverse(v.begin(),v.end());
            }

            for(int i = 0; i < v.size(); i++){
                res.push_back(v[i]);
            }
        }

        return res;
    }
};