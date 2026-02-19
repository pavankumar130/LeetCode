class Solution {
public:
    int countBinarySubstrings(string s) {
        int res = 0;

        int prev = 1e9;
        int cnt = 1;
        for(int i = 1; i < s.size(); i++){
            if(s[i - 1] == s[i]){
                cnt++;
            }
            else{
                if(prev != 1e9){
                    res += min(cnt, prev);
                }
                prev = cnt;
                cnt = 1;
            }
        }

        if(prev != 1e9){
            res += min(cnt, prev);
        }

        return res;
    }
};