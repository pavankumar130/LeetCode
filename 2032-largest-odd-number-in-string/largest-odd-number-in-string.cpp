class Solution {
public:
    string largestOddNumber(string num) {
        
        int n=num.size();

        for(int i=n-1; i>=0; i--){
            int temp = num[i]-'0';
            if(temp%2 != 0){
                string str;

                for(int j=0; j<=i; j++){
                    str.push_back(num[j]);
                }

                return str;
            }
        }
        return "";
    }
};