class Solution {
    static bool cmp(pair<int,int>&a, pair<int,int>&b){
        if(a.first != b.first){
            return a.first < b.first;
        }

        return a.second > b.second;
    }

public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int>mp;

        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }

        vector<pair<int,int>>arr;

        for(auto it: mp){
            arr.push_back({it.second, it.first});
        }

        sort(arr.begin(), arr.end(), cmp);

        vector<int>res;

        for(int i = 0; i < arr.size(); i++){
            for(int j = 0; j < arr[i].first; j++){
                res.push_back(arr[i].second);
            }
        }

        return res;
    }
};