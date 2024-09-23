class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        int cnt = 0;

        map<string,int>mp;

        for(auto it: bannedWords){
            mp[it]++;
        }

        for(auto it: message){
            if(mp.find(it) != mp.end()){
                cnt++;
            }
        }

        if(cnt >= 2){
            return true;
        }

        return false;
    }
};