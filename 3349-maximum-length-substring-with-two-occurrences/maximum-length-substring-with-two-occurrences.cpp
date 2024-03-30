class Solution {
public:
    int maximumLengthSubstring(string s) {
        int res = 0;
        int n = s.size();
        vector<int>freq(26, 0);
        int i = 0, j = 0;

        while(i < n){
            freq[s[i] - 'a']++;

            while(freq[s[i] - 'a'] > 2){
                freq[s[j] - 'a']--;
                j++;
            }
            res = max(res, i - j + 1);
            i++;
        }
        return res;
    }
};