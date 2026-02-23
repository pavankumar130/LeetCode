class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string>st;
        int n = s.size();

        for(int i = 0; i <= (n - k); i++){
            string temp = "";
            for(int j = i; j < i + k; j++){
                temp += s[j];
            }

            st.insert(temp);
        }
        // for(auto it: st){
        //     cout<<it<<" ";
        // }

        // cout<<endl;
        // cout<<st.size()<<" "<<pow(2, k)<<endl;
        return st.size() == pow(2, k);
    }
};