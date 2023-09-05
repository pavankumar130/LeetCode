class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        int n=num.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && k && st.top() > num[i]){
                k--;
                st.pop();
            }
            if(!st.empty() || num[i] != '0' ){
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
        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};