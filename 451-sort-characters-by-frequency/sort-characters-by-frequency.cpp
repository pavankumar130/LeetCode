class Solution {

    static bool cmp(pair<int,char>&a, pair<int,char>&b){
        if(a.first != b.first){
            return a.first > b.first;
        }
        return a.second < b.second;
    }
public:
    string frequencySort(string s) {
        map<char,int>mp;

        for(auto it:s){
            mp[it]++;
        }

        vector<pair<int,char>>arr;
        for(auto it:mp){
            arr.push_back({it.second,it.first});
        }

        sort(arr.begin(),arr.end(),cmp);
        string res = "";
        for(int i = 0; i < arr.size(); i++){
            for(int j = 0; j < arr[i].first; j++){
                res += arr[i].second;
            }
        }
        return res;
    }
};