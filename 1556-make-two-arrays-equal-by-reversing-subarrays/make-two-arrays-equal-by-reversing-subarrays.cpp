class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int,int>mp1, mp2;

        for(auto it: target){
            mp1[it]++;
        }

        for(auto it: arr){
            mp2[it]++;
        }
    
        for(auto it: mp1){
            if(mp2.find(it.first) == mp2.end() || mp2[it.first] != it.second){
                return false;
            }
        }

        return true;
    }
};