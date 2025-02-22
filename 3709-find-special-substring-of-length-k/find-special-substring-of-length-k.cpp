class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        if(s.size() < k){
            return false;
        }

        for(int i = 0; i <= s.size() - k; i++){
            char ch = s[i];
            bool is_sub = true;

            for(int j = i; j < (i + k); j++){
                if(s[j] != ch){
                    is_sub = false;
                    break;
                }
            }

            if(is_sub){
                bool left = (i == 0 || s[i - 1] != ch);
                bool right = (i + k == s.size() || s[i+k] != ch);

                if(left && right){
                    return true;
                }
            }
        }

        return false;
    }
};