// class Solution {
// public:
    // int countPalindromicSubsequence(string s) {
    //     vector<int>right(26,0);
    //     vector<int>left(26,0);

    //     for(int i=0; i<s.length();i++){
    //         right[s[i]-'a']++;
    //     }
    //     unordered_set<string>st;

    //     for(int i=0; i<s.length(); i++){
    //         right[s[i]-'a']--;

    //         for(int j=0; j<26; j++){
    //             if(left[j] >0 && right[j] > 0){
    //                char ch='a'+j;

    //                string palindrome="";
    //                palindrome+=ch;
    //                palindrome+=s[i];
    //                palindrome+=ch;

    //                if(st.count(palindrome)){
    //                    continue;
    //                }
    //                st.insert(palindrome);
    //             }
    //         }

    //         left[s[i]-'a']++;
    //     }
    //     return st.size();
    // }
// };
class Solution {
public:
bool solve(vector<int>&arr, int l, int r){
    auto it = upper_bound(arr.begin(),arr.end(),l);

    if(it == arr.end()){
        return false;
    }
    return (*it < r);
}
    int countPalindromicSubsequence(string s) {
        vector<vector<int>>arr(26);
        for(int i=0; i<s.length(); i++){
            arr[s[i]-'a'].push_back(i);
        }

        int count=0;
        for(char i='a'; i<='z'; i++){
            if(arr[i-'a'].size() >= 2){
                for(char j='a'; j<='z'; j++){
                    if(arr[j-'a'].size() > 0 && 
                             solve(arr[j-'a'],arr[i-'a'][0],arr[i-'a'].back())){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};