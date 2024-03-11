class Solution {
    static map<char,int> mp;
    static bool cmp(char a, char b){
        if(mp.find(a) != mp.end() && mp.find(b) != mp.end()){
            int ind1 = mp[a];
            int ind2 = mp[b];
            return ind1 < ind2;
        }
        if(mp.find(a) != mp.end()){
            return true;
        }
        return false;
    }
public:
    string customSortString(string order, string s) {
        for(int i = 0; i < order.size(); i++){
            mp[order[i]] = i;
        }
        sort(s.begin(), s.end(), cmp);
        return s;
    }
};

map<char, int> Solution::mp;
