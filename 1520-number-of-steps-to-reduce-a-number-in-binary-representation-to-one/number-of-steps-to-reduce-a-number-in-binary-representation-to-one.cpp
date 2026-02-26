class Solution {
public:
    int numSteps(string s) {
        int n = s.size();
        int cnt = 0;

        while(s.size() > 1){
            if(s.back() == '0'){
                s.pop_back();
            }
            else{
                bool flag = false;
                for(int i = s.size() - 1; i >= 0; i--){
                    if(s[i] == '1'){
                        s[i] = '0';
                    }
                    else{
                        flag = true;
                        s[i] = '1';
                        break;
                    }
                }

                if(!flag){
                    s = "1" + s;
                }
            }
            cnt++;
        }

        return cnt;
    }
};