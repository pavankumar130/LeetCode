class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int>freq(26, 0);

        int deleted = 0, ans = word.size();

        for(auto it: word){
            freq[it - 'a']++;
        }

        sort(freq.begin(), freq.end());

        for(int i = 0; i < freq.size(); i++){
            int res = deleted, minfreq = freq[i];
            for(int j = freq.size() - 1; j > i; j--){
                if(freq[j] - minfreq <= k){
                    break;
                }
                res += freq[j] - minfreq - k;
            }

            ans = min(ans, res);
            deleted += freq[i];
        }

        return ans;
    }
};