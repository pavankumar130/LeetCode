class Solution {
public:
    string reverseWords(string s) {
        vector<string>temp;
        string st="";
        for(int i=0;i<s.size();i++){
            if(s[i] == ' '){
                if(st.size() == 0){
                    continue;
                }
                temp.push_back(st);
                st="";
            }
            else{
                st.push_back(s[i]);
            }
        }
        if(st.size() != 0){
            temp.push_back(st);
            st="";
        }
        reverse(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++){
            st+=temp[i];
            if(i != temp.size()-1){
                st+=" ";
            }
        }
        return st;
    }
};