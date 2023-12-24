class Solution {
    string startsWith1(int n){
        string str;
        for(int i=0; i<n; i++){
            if(i%2 == 0){
                str.push_back('1');
            }
            else{
                str.push_back('0');
            }
        }
        return str;
    }
    string startsWith0(int n){
        string str;
        for(int i=0; i<n; i++){
            if(i%2 == 0){
                str.push_back('0');
            }
            else{
                str.push_back('1');
            }
        }
        return str;
    }
public:
    int minOperations(string s) {
        int n=s.length();
        
        string strs0 = startsWith0(n);
        string strs1 = startsWith1(n);
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i=0; i<n; i++){
           if(s[i] != strs0[i]){
               cnt1++;
           }
        }

        for(int i=0; i<n; i++){
           if(s[i] != strs1[i]){
               cnt2++;
           }
        }

        return min(cnt1,cnt2);
    }
};