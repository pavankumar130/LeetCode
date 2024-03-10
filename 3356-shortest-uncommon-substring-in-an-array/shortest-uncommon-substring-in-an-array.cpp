class Solution {
    void FindSub(string &str, map<string,set<int>>&mp, int ind){
        int n = str.size();

        for(int i = 0; i < n; i++){
            string temp = "";
            for(int j = i; j < n; j++){
                temp += str[j];
                mp[temp].insert(ind);
            }
        }
    }
    static bool cmp(string &a, string &b){
        if(a.size() != b.size()){
            return a.size() < b.size();
        }

        int i = 0;
        while(i < a.size()){
            if(a[i] == b[i]){
                i++;
                continue;
            }
            if(a[i] < b[i]){
                return true;
            }
            else{
                return false;
            }
        }
        return false;
    }
    string solve(string &str, map<string,set<int>>&mp, int ind){
        vector<string>pq;

        for(int i = 0; i < str.size(); i++){
            string temp = "";
            for(int j = i; j < str.size(); j++){
                temp += str[j];

                if(mp[temp].size() == 1 && mp[temp].find(ind) != mp[temp].end()){
                    pq.push_back(temp);
                }
            }
        }

        if(pq.size() == 0){
            return "";
        }

        sort(pq.begin(),pq.end(),cmp);
        return pq[0];
    }
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        map<string,set<int>>mp;

        for(int i = 0; i < arr.size(); i++){
            FindSub(arr[i], mp, i);
        }

        vector<string>res(arr.size());
        for(int i = 0; i < arr.size(); i++){
            res[i] = solve(arr[i], mp, i);
        }
        return res;
    }
};