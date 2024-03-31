#define ll long long
class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int n = nums.size();
        unordered_map<ll,ll>mp;
        set<pair<ll,ll>, greater<pair<ll,ll>>>s;

        vector<ll>res(n);

        for(int i = 0; i < n; i++){
            ll el = nums[i];
            pair<ll,ll>p = {mp[el], el};

            if(s.find(p) != s.end()){
                s.erase(p);
            }

            mp[el] += freq[i];

            p = {mp[el], el};
            s.insert(p);
            res[i] = (s.begin()->first);
        }
      return res;
    }
};