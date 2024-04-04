class Solution {
public:
    int maxDepth(string s) {

        int n = s.size();
        int res = 0;
        int cnt = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                cnt++;
            }
            else if((s[i] >= '0' && s[i] <= '9') || 
                (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')){

                    cout<<s[i] <<" ";
                    res = max(res, cnt);
            }
            else{
                res = max(res, cnt);
                cnt--;
            }
        }
        return res;
    }
};