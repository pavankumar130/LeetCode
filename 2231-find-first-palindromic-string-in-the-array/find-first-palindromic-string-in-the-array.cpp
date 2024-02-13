class Solution {
    bool solve(string &str){
        int low = 0, high = str.length()-1;

        while(low <= high){
            if(str[low] != str[high]){
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        int n = words.size();

        for(int i = 0; i < n; i++){
            if(solve(words[i])){
                return words[i];
            }
        }
        return "";
    }
};