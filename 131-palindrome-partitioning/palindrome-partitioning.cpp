class Solution {
public:
bool palindrome(int start, int end, string &s){

    while(start <= end){
        if(s[start] != s[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}
void solve(int ind, string &s, vector<vector<string>>&res,vector<string>&temp){
    if(ind >= s.length()){
       res.push_back(temp);
       return;
    }
    
    for(int i=ind; i<s.length(); i++){
        if(palindrome(ind,i,s)){
            string str = s.substr(ind, i-ind+1);
            temp.push_back(str);
            solve(i+1,s,res,temp);
            temp.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>temp;
        solve(0,s,res,temp);
        return res;
    }
};