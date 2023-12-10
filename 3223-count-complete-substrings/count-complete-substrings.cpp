class Solution {
public:
    int countCompleteSubstrings(string word, int k) {
        int n=word.size();

        vector<vector<int>>prefreq(n+1,vector<int>(26,0));
        for(int i=0; i<n; i++){
            prefreq[i+1] = prefreq[i];
            prefreq[i+1][word[i]-'a']++;
        }

        int len = 0, res = 0;
        for(int i=0; i<n; i++){
            if(i >= 1 && abs(word[i] - word[i-1]) > 2){
                len = i;
            }

            for(int j = 1; j<=26; j++){
                int length = j*k;
                int expected = i - length +1;
                if(expected < len){
                    break;
                }

                bool flag = true;
                for(char ch = 'a'; ch <= 'z'; ch++){
                    int freq = prefreq[i+1][ch-'a'] - prefreq[expected][ch-'a'];
                    if(freq != 0 && freq != k){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    res++;
                }
            }
        }
      return res;
    }
};