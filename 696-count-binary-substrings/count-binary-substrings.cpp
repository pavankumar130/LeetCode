class Solution {
public:
    int countBinarySubstrings(string s) {
        int res = 0;

        int prev = 0;
        int cnt = 1;
        for(int i = 1; i < s.size(); i++){
            if(s[i - 1] == s[i]){
                cnt++;
            }
            else{
                res += min(cnt, prev);
                prev = cnt;
                cnt = 1;
            }
        }
        
        res += min(cnt, prev);

        return res;
    }
};