class Solution {
public:
    int vowelConsonantScore(string s) {
        int n = s.size();
        int v = 0;
        int c = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                v++;
            }
            else if(s[i] == ' ' || s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || 
            s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9'){
                continue;
            }
            else{
                c++;
            }
        }

        if(c > 0){
            return floor(v / c);
        }

        return 0;
    }
};