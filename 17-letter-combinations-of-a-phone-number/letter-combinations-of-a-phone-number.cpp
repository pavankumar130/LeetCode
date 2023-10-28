class Solution {
public:
void solve(string temp, vector<string>&res,unordered_map<char,vector<char>>&mp,string &digits, int ind){
    if(ind == digits.size()){
        res.push_back(temp);
        return;
    }
    for(auto it:mp[digits[ind]]){
        temp.push_back(it);
        solve(temp,res,mp,digits,ind+1);
        temp.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0){
            return {};
        }
        unordered_map<char,vector<char>>mp;
        mp['2']={'a','b','c'};
        mp['3']={'d','e','f'};
        mp['4']={'g','h','i'};
        mp['5']={'j','k','l'};
        mp['6']={'m','n','o'};
        mp['7']={'p','q','r','s'};
        mp['8']={'t','u','v'};
        mp['9']={'w','x','y','z'};
       
        vector<string>res;
        string temp;
        solve(temp,res,mp,digits,0);
        return res;
    }
};