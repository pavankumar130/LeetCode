class Solution {
    vector<int> countFreq(string &str){
        vector<int>freq(26, 0);

        for(auto it: str){
            freq[it - 'a']++;
        }

        return freq;
    }

    vector<int> solve(const vector<int>&a, const vector<int>&b){
        vector<int>res(26, 0);

        for(int i = 0; i < 26; i++){
            res[i] = min(a[i], b[i]);
        }

        return res;
    }
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int>last = countFreq(words[0]);

        for(int i = 1; i < words.size(); i++){
            last = solve(last, countFreq(words[i]));
        }

        vector<string>res;
        for(int i = 0; i < 26; i++){
            while(last[i] > 0){
                res.push_back(string(1, 'a' + i));
                last[i]--;
            }
        }

        return res;
    }
};