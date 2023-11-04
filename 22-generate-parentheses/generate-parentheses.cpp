class Solution {
public:
void solve(int open, int close, vector<string>&res, string temp){
    if(open == 0 && close == 0){
        res.push_back(temp);
        return;
    }
    if(open == close){
        temp.push_back('(');
        solve(open-1,close,res,temp);
    }
    else{
        if(open >0){
            temp.push_back('(');
            solve(open-1,close,res,temp);
            temp.pop_back();
        }
        temp.push_back(')');
        solve(open,close-1,res,temp);
    }
}
    vector<string> generateParenthesis(int n) {
        if(n == 0){
            return {};
        }
        vector<string>res;
        string temp;
        solve(n,n,res,temp);
        return res;
    }
};