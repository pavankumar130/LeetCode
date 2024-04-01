class Solution {
public:
    int lengthOfLastWord(string s) {
        string curr="";

        int n=s.length();
        for(int i=n-1;i>=0;i--){
            if(s[i] == ' '){
                if(curr.length() == 0){
                    continue;
                }
                else{
                    return curr.length();
                }
            }
            else{
                curr.push_back(s[i]);
            }
        }
        return curr.length();
    }
};