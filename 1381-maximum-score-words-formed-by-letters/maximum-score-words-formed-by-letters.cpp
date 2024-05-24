class Solution {
    int a[26], b[26], ans = 0;
    void solve(int ind, vector<string>& words, vector<int>& score){
        if(ind == words.size()){
            int sc = 0;
            for(int i = 0; i < 26; i++){
                if(b[i] > a[i]){
                    return;
                }
                sc += score[i] * b[i];
            }
            ans = max(ans, sc);
            return;
        }

        solve(ind + 1, words, score);
        for(auto it: words[ind]){
            b[it - 'a']++;
        }
        solve(ind + 1, words, score);
        for(auto it: words[ind]){
            b[it - 'a']--;
        }
    }
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        for(auto it: letters){
            a[it - 'a']++;
        }
        solve(0, words, score);
        return ans;
    }
};