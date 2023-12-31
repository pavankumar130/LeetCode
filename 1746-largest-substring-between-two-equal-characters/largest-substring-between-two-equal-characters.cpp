class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.length();

        int size = -1;

        for(int i=0; i<n; i++){
            char ch = s[i];
            for(int j = i+1; j< n; j++){
                if(s[j] == ch){
                    size = max(size, (j-i-1));
                }
            }
        }
        return size;
    }
};