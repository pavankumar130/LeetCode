class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int num = 0;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '1'){
                num++;
            }
        }
        string res ;
        if(num == 1){
            for(int i = 0; i < s.length()-1; i++){
                res.push_back('0');
            }
            res.push_back('1');
            return res;
        }
        for(int i = 0; i < num -1; i++){
            res.push_back('1');
        }
        for(int i = num - 1; i < s.length()-1; i++){
            res.push_back('0');
        }
        res.push_back('1');
        return res;
    }
};