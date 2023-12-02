class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int>mp(26,0);
        for(int i=0; i<chars.length(); i++){
            mp[chars[i]-'a']++;
        }
        
        int ans=0;
        for(int i=0; i<words.size(); i++){
            vector<int>temp(26,0);
            for(char it:words[i]){
                temp[it-'a']++;
            }
            bool have = true;
            for(int i=0; i<26; i++){
               if(mp[i] < temp[i]){
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