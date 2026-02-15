class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int n = a.size();
        int m = b.size();

        int i = n - 1;
        int j = m - 1;
        char carry = '0';

        while(i >= 0 && j >= 0){
            if(a[i] == '1' && b[j] == '1' && carry == '1'){
                res += "1";
                carry = '1';
            }
            else if(a[i] == '1' && b[j] == '1' && carry == '0'){
                res += "0";
                carry = '1';
            }
            else if((a[i] == '1' || b[j] == '1') && carry == '1'){
                res += '0';
                carry = '1';
            }
            else if((a[i] == '1' || b[j] == '1') && carry == '0'){
                res += '1';
                carry = '0';
            }
            else if(a[i] == '0' && b[j] == '0' && carry == '1'){
                res += '1';
                carry = '0';
            }
            else{
                res += '0';
                carry = '0';
            }

            i--;
            j--;
        }

        while(i >= 0){
            if(a[i] == '1' && carry == '1'){
                res += "0";
                carry = '1';
            }
            else if(a[i] == '1' || carry == '1'){
                res += '1';
                carry = '0';
            }
            else{
                res += '0';
                carry = '0';
            }
            i--;
        }

        while(j >= 0){
            if(b[j] == '1' && carry == '1'){
                res += "0";
                carry = '1';
            }
            else if(b[j] == '1' || carry == '1'){
                res += '1';
                carry = '0';
            }
            else{
                res += '0';
                carry = '0';
            }
            j--;
        }

        if(carry == '1'){
            res += '1';
        }
        reverse(res.begin(), res.end());
        return res;
    }
};