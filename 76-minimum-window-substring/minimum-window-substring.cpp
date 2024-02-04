class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() == 0 || t.size() == 0 || s.size() < t.size()){
            return "";
        }
        vector<int>v(256,0);
        for(auto it:t){
            v[it]++;
        }
        int i=0,j=0,start=0,mini=INT_MAX,count=0;
        while(i<s.size()){
            if(v[s[i]]>0){
                count++;
            }
            v[s[i]]--;
            while(count == t.size()){
                if(mini > (i-j+1)){
                    mini=i-j+1;
                    start=j;
                }
                v[s[j]]++;
                if(v[s[j]] > 0){
                    count--;
                }
                j++;
            }
            i++;
        }
        if(mini == INT_MAX){
            return "";
        }
        return s.substr(start,mini);
    }
};