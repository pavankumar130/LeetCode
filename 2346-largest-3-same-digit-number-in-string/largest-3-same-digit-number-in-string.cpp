class Solution {
public:
    string largestGoodInteger(string num) {
        int res = -1;
        for(int i=1; i<num.length()-1; i++){
            if(num[i] == num[i-1] && num[i] == num[i+1]){
                if(num[i]-'0' > res){
                    res = num[i]-'0';
                }
            }
        }
        if(res == -1){
            return "";
        }
        string str;
        str.push_back(res+'0');
        str.push_back(res+'0');
        str.push_back(res+'0');
        return str;
    }
};