class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int>right(26,0);
        vector<int>left(26,0);

        for(int i=0; i<s.length();i++){
            right[s[i]-'a']++;
        }
        unordered_set<string>st;

        for(int i=0; i<s.length(); i++){
            right[s[i]-'a']--;

            for(int j=0; j<26; j++){
                if(left[j] >0 && right[j] > 0){
                   char ch='a'+j;

                   string palindrome="";
                   palindrome+=ch;
                   palindrome+=s[i];
                   palindrome+=ch;

                   if(st.count(palindrome)){
                       continue;
                   }
                   st.insert(palindrome);
                }
            }

            left[s[i]-'a']++;
        }
        return st.size();
    }
};