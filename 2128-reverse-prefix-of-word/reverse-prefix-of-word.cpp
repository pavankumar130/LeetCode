class Solution {
    void reverse(int s, int e, string &word){
        while(s <= e){
            swap(word[s], word[e]);
            e--;
            s++;
        }
    }
public:
    string reversePrefix(string word, char ch) {
        int n = word.size();

        for(int i = 0; i < n; i++){
            if(word[i] == ch){
                reverse(0, i, word);
                break;
            }
        }
        return word;
    }
};