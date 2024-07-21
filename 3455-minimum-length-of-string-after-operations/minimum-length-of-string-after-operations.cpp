class Solution {
public:
    int minimumLength(string s) {
        map<char,int>mp;

        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++;
        }

        int cnt = 0;

        for(auto it: mp){
            if(it.second <= 2){
                cnt += it.second;
            }
            else{
                while(it.second > 2){
                    it.second -= 2;
                }

                cnt += it.second;
            }
        }

        return cnt;
    }
};