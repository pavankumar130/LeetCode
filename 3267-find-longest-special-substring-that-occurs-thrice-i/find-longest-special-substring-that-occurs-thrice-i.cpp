class Solution {
public:
    int maximumLength(string s) {
        
        unordered_map<string,int>mp;
        
        for(int i = 0; i < s.length(); i++){
            string temp = "";
            temp+=s[i];
            mp[temp]++;
            for(int j = i+1; j < s.length(); j++){
                if(s[i] == s[j]){
                    temp += s[j];
                    mp[temp]++;
                }
                else{
                    break;
                }
            }
        }
        
        int maxi = -1;
        for(auto it:mp){
            if(it.second >= 3){
                int val = (it.first).size();
                maxi = max(maxi,val);
            }
        }
        
        return maxi;
        
    }
};