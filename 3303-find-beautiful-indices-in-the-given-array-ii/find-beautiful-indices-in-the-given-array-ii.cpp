class Solution {
    vector<int>z_function(string s){
        int n = s.size();
        vector<int>z(n);
        int l = 0, r = 0;
        for(int i = 1; i < n; i++){
            if(i < r){
                z[i] = min(r-i, z[i-l]);
            }
            while(i+z[i] < n && s[z[i]] == s[i+z[i]]){
                z[i]++;
            }
            if(i + z[i] > r){
                l = i;
                r = i + z[i];
            }
        }
        return z;
    }
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int>v1,v2;
        v1 = z_function(a+s);
        v2 = z_function(b+s);

        vector<int>v11;
        set<int>st;
        for(int i = a.size(); i < v1.size(); i++){
            if(v1[i] >= a.size()){
                v11.push_back(i-a.size());
            }
        }
        for(int i = b.size(); i < v2.size(); i++){
            if(v2[i] >= b.size()){
                st.insert(i-b.size());
            }
        }

        vector<int>res;

        for(int i = 0; i<v11.size(); i++){
            cout<<v11[i]<<" ";
            auto it = st.lower_bound(v11[i]);
            bool flag = false;

            if(it != st.end()){
                if(*it - v11[i] <= k){
                    flag = true;
                }
            }
            if(it != st.begin()){
                it--;
                if(v11[i]-*it <= k){
                    flag = true;
                }
            }
            if(flag){
                res.push_back(v11[i]);
            }
        }
        return res;
    }
};