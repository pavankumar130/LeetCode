class Solution {
public:
    bool isSubstringPresent(string s) {
        
        map<string,int>mp;
        int n = s.size();
        
        for(int i = 1; i < n; i++){
            string temp = "";
            temp +=s[i - 1];
            temp += s[i];
            cout<<temp<<" ";
            mp[temp]++;
        }
        
        reverse(s.begin(), s.end());
        
        for(int i = 1; i < n; i++){
            string temp = "";
            temp +=s[i - 1];
            temp += s[i];
            cout<<temp<<" ";
            if(mp.find(temp) != mp.end()){
                return true;
            }
        }
        
        return false;
    }
};