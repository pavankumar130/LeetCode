class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        vector<int>res;
        for(auto it:mp){
            if(it.second > 1){
                res.push_back(it.first);
            }
        }
        return res;
    }
};