class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int>mp;

        for(auto it: s){
            mp[it]++;
        }

        int even = 0, odd = 0;

        for(auto it: mp){
            if(it.second %2){
                even += (it.second - 1);
                odd = true;
            }
            else{
                even += (it.second);
            }
        }

        if(odd){
            return (even + 1);
        }
        return even;
    }
};