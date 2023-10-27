class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        if(n<=1){
            return s;
        }

        int maxi=1;
        int start=0;
        int end=0;

        for(int i=0;i<n;i++){
            int l=i,r=i;
            while(l>=0 && r<n && s[l] == s[r]){
                l--;
                r++;
            }
            int len=(r-l-1);
            if(maxi < len){
                maxi=len;
                start=l+1;
                end=r-1;
            }
        }

        for(int i=0;i<n;i++){
            int l=i,r=i+1;
            while(l>=0 && r<n && s[l] == s[r]){
                l--;
                r++;
            }
            int len=(r-l-1);
            if(maxi < len){
                maxi=len;
                start=l+1;
                end=r-1;
            }
        }

        return s.substr(start,maxi);
    }
};