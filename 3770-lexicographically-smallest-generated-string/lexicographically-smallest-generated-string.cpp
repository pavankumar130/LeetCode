class Solution {
    bool same(string &word, string &str2, int start, int size){
        int ind = 0;
        for(int i = start; i < start + size; i++){
            if(word[i] != str2[ind]){
                return false;
            }

            ind++;
        }

        return true;
    }
public:
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        int N = n + m - 1;
        string word(N, 'A');
        vector<bool>can_change(N, false);

        // Process for T
        for(int i = 0; i < n; i++){
            if(str1[i] == 'T'){
                int i_ = i;
                for(int j = 0; j < m; j++){
                    // if any overlap in 'T'
                    if(word[i_] != 'A' && word[i_] != str2[j]){
                        return "";
                    }
                    word[i_++] = str2[j];
                }
            }
        }

        // Fill Remaining with 'a'
        for(int i = 0; i < N; i++){
            if(word[i] == 'A'){
                word[i] = 'a';
                can_change[i] = true;
            }
        }

        // Process the 'F'
        for(int i = 0; i < n; i++){
            if(str1[i] == 'F'){
                if(same(word, str2, i, m)){
                    bool changed = false;
                    for(int j = i + m - 1; j >= i; j--){
                        if(can_change[j]){
                            word[j] = 'b';
                            changed = true;
                            break;
                        }
                    }

                    if(!changed){
                        return "";
                    }
                }
            }
        }

        return word;
    }
};