class Solution {
public:
void solve(int ind, unordered_set<string>&st,string &s, vector<string>&res, string temp){
    if(ind >= s.length()){
        temp.pop_back();
        res.push_back(temp);
        return;
    }
    
    string str="";
    for(int i=ind; i<s.length(); i++){
        str+=s[i];
        if(st.find(str) != st.end()){
            solve(i+1,st,s,res,temp+str+" ");
        }
    }
}
    vector<string> wordBreak(string s, vector<string>& dict) {
        unordered_set<string>st;
        for(auto it:dict){
            st.insert(it);
        }
        
        vector<string>res;
        string temp;
        solve(0,st,s,res,temp);
        return res;
    }
};