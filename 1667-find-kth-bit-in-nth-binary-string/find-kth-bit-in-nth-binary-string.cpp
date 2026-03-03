class Solution {
    string reverse_invert(string str){
        for(int i = 0; i < str.size(); i++){
            if(str[i] == '0'){
                str[i] = '1';
            }
            else{
                str[i] = '0';
            }
        }

        reverse(str.begin(), str.end());
        return str;
    }
    string solve(int n){
        if(n == 1){
            return "0";
        }

        string str = solve(n - 1);
        return (str + "1" + reverse_invert(str));
    }
public:
    char findKthBit(int n, int k) {
        
        string str = solve(n);
        cout<<str<<endl;
        return str[k - 1];
    }
};