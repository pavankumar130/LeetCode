class Solution {
    bool palindrome(string &s){
        int low = 0;
        int high = s.length()-1;

        while(low <= high){
            if(s[low] != s[high]){
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
public:
    int countSubstrings(string s) {
        int n = s.length();
        int res = 0;
        for(int i = 0; i < n; i++){
            string temp = "";
            for(int j = i; j < n; j++){
                temp += s[j];
                if(palindrome(temp)){
                    res++;
                }
            }
        }
        return res;
    }
};