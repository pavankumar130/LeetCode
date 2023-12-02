class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int>mp;
        for(int i=0; i<chars.length(); i++){
            mp[chars[i]]++;
        }
        
        int ans=0;
        for(int i=0; i<words.size(); i++){
            unordered_map<char,int>temp;
            for(char it:words[i]){
                temp[it]++;
            }
            bool have = true;
            for(auto it:temp){
               if(mp.find(it.first) == mp.end() || mp[it.first] < it.second){
                   have = false;
                   break;
               }
            }
            if(have){
                ans += words[i].length();
            }
        }

        return ans;
    }
};