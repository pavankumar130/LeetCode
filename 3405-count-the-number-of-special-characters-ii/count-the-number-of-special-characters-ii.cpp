class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>cap(26, -1), small(26, -1);

        for(int i = 0; i < word.size(); i++){
            if(word[i] >= 'A' && word[i] <= 'Z' ){
                if(cap[word[i]-'A'] == -1){
                    cap[word[i] - 'A'] = i;
                }
            }
            else{
                small[word[i] - 'a'] = i;
            }
        }

        int cnt = 0;

        for(int i = 0; i < 26; i++){
            //cout<<small[i] <<" "<<cap[i] <<endl;
            if(small[i] != -1 && cap[i] != -1 && small[i] < cap[i]){
                cnt++;
            }
        }

        return cnt;
    }
};