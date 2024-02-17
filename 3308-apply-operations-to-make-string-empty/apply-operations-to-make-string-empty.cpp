class Solution {
public:
    string lastNonEmptyString(string s) {
        int n = s.length();

        unordered_map<char,vector<int>>mp;

        for(int i = 0; i < n; i++){
            mp[s[i]].push_back(i);
        }

        vector<pair<int,char>>temp;
        int maxi = 0;
        for(auto it:mp){
            maxi = max(maxi, (int)it.second.size());
        }

        for(auto it:mp){
            if(it.second.size() == maxi){
                temp.push_back({it.second.back(),it.first});
            }
        }

        sort(temp.begin(),temp.end());

        string res = "";
        for(int i = 0; i < temp.size(); i++){
            res += temp[i].second;
        }
        return res;
    }
};