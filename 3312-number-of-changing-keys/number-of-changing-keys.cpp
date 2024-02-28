class Solution {
public:
    int countKeyChanges(string s) {
        int n = s.length();

        for(int i = 0; i < n; i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                continue;
            }
            int num = s[i] - 'A';
            s[i] = num + 'a';
        }

        int num = 0;
        int prev = s[0];
        int i = 1;
        while(i < n){
            if(s[i] == prev){
                i++;
                continue;
            }
            num++;
            prev = s[i];
            i++;
        }
        return num;
    }
};