class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int cnt_one = 0;
        int cnt_zero = 0;

        for(int i = 0; i < n; i++){
            // start with zero
            if(i % 2 == 0){
                if(s[i] != '0'){
                    cnt_zero++;
                }
            }
            else{
                if(s[i] != '1'){
                    cnt_zero++;
                }
            }

            // start with one
            if(i % 2 == 0){
                if(s[i] != '1'){
                    cnt_one++;
                }
            }
            else{
                if(s[i] != '0'){
                    cnt_one++;
                }
            }
        }

        return min(cnt_one, cnt_zero);
    }
};