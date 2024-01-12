class Solution {
public:
    bool halvesAreAlike(string s) {
        int cnt1 = 0;

        for(int i = 0; i < s.length()/2; i++){
            char ch = s[i];
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                cnt1++;
            }
            else if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'){
                cnt1++;
            }
        }

        int cnt2 = 0;
        for(int i = s.length()/2; i < s.length(); i++){
            char ch = s[i];
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                cnt2++;
            }
            else if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'){
                cnt2++;
            }
        }
        return cnt1 == cnt2;
    }
};