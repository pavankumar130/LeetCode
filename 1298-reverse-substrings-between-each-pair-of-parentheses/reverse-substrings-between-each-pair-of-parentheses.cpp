class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        for(int i = 0; i < s.size(); i++){

            if(s[i] == ')'){
                string rev = "";
                while(!st.empty() && st.top() != '('){
                    rev += st.top();
                    st.pop();
                }

                if(!st.empty()){
                    st.pop();
                }

                for(int j = 0; j < rev.size(); j++){
                    st.push(rev[j]);
                }
            }
            else{
                st.push(s[i]);
            }
        }

        string res = "";

        while(!st.empty()){
            res = st.top() + res;
            st.pop();
        }

        return res;
    }
};