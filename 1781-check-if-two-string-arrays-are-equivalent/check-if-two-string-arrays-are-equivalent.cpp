class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0, j = 0;
        for(string &s: word1){
            for(char &c: s){
                if(i == word2.size() or word2[i][j] != c) return false;
                j++;
                if(j == word2[i].size()){
                    i++;
                    j = 0;
                }
            }
        }
        return i == word2.size();
    }
};