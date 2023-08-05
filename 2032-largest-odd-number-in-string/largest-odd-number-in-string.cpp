class Solution {
public:
    string largestOddNumber(string num) 
    {
        string s = "";
        int rem = num.length();

        for(int i = num.length()-1 ; i >= 0 ;  i--)
        {
            int digit = num[i] - '0';

            if(digit & 1)
            {
                return num.substr(0,rem);
            }

            rem--;
        }

        return s;    
    }
};