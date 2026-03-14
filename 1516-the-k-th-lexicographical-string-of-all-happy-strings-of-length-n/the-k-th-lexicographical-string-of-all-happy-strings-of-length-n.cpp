class Solution {
    void solve(int n, string curr, vector<string>&happystr){
        if(curr.size() == n){
            happystr.push_back(curr);
            return;
        }

        for(char ch = 'a'; ch <= 'c'; ch++){
            if(!curr.empty() && curr.back() == ch){
                continue;
            }

            solve(n, curr + ch, happystr);
        }
    }
public:
    string getHappyString(int n, int k) {
        vector<string>happystr;
        solve(n, "", happystr);

        if(happystr.size() < k){
            return "";
        }
        return happystr[k - 1];
    }
};