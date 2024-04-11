class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;

        for(int i = 0; i < num.size(); i++){

            while(!st.empty() && k && st.top() > num[i]){
                k--;
                st.pop();
            }
            if(!st.empty() || num[i] != '0'){
                st.push(num[i]);
            }
        }

        while(!st.empty() && k){
            st.pop();
            k--;
        }

        if(st.size() == 0){
            return "0";
        }

        string res ;

        while(!st.empty()){
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};