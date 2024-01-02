// class Solution {
// public:
//     vector<vector<int>> findMatrix(vector<int>& nums) {
//         vector<vector<int>>res;
//         unordered_map<int,int>mp;
//         for(int i=0; i<nums.size(); i++){
//             mp[nums[i]]++;
//         }

//         while(mp.size() > 0){
//             vector<int>temp;
//             for(auto i = mp.begin(); i!= mp.end(); i++){
//                 temp.push_back(i->first);
//                 mp[i->first]--;
//                 if(mp[i->first] == 0){
//                     mp.erase(i->first);
//                 }
//             }
//             res.push_back(temp);
//         }
//         return res;
//     }
// };
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        while (mp.size() > 0) {
            vector<int> temp;
            auto it = mp.begin();
            while (it != mp.end()) {
                temp.push_back(it->first);
                it->second--;

                if (it->second == 0) {
                    it = mp.erase(it);
                } else {
                    it++;
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};
