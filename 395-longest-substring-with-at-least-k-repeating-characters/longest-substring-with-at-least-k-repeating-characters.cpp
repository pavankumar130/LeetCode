class Solution {
public:
    int longestSubstring(string s, int k) {
        int n=s.size();
        if(n<k) return 0;
        if(k<2)  return n;
        map<char, int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }

        int i=0, a=0, b=0;
        while(i<n && mp[s[i]]>=k){
            i++; 
        }
        if(i==n) return i;
        a=longestSubstring(s.substr(0, i), k);
        if(i<n-1)
        b=longestSubstring(s.substr(i+1), k);
        return max(a, b);
    }
};