class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int res = 1;
        int n = word.size();

        for(int i = k; i < n; i+=k){
            string s1 = word.substr(i,n-i);
            string s2 = word.substr(0,n-i);
            if(s1 == s2){
                return res;
            }
            else{
                res++;
            }
        }
        return res;
    }
};