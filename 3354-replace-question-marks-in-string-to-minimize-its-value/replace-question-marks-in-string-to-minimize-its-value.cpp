class Solution {
public:
    string minimizeStringValue(string s) {
        string res = "";

        vector<int>freq(26, 0);

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '?'){
                continue;
            }
            freq[s[i] - 'a']++;
        }

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '?'){
                int min_char = 0;
                for(int j = 0; j < 26; j++){
                    if(freq[j] < freq[min_char]){
                        min_char = j;
                    }
                }

                res += char('a' + min_char);
                freq[min_char]++;
            }
        }

        sort(res.begin(), res.end());
        int ind = 0;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '?'){
                s[i] = res[ind++];
            }
        }

        return s;
    }
};