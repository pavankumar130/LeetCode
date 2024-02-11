class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        int n = words.size();

        vector<int>size,freq(26,0);
        for(int i = 0; i < n; i++){
            size.push_back(words[i].size());
            for(int j = 0; j < words[i].size(); j++){
                freq[words[i][j] - 'a']++;
            }
        }
        sort(size.begin(), size.end());
        int odd = 0, even = 0;

        for(int i = 0; i < 26; i++){
            even += freq[i]/2;
            odd += freq[i]%2;
        }

        int res = 0;
        for(int i = 0; i < n; i++){
            if(size[i]%2 == 1){
                if(odd){
                    odd--;
                }
                else{
                    even--;
                    odd++;
                }
            }
            if(even < size[i]/2){
                break;
            }
            even -= size[i]/2;
            res++;
        }
        return res;
    }
};