class Solution {
public:
    int reverse(int x) {
        bool sign = false;
        if(x < 0){
            sign = true;
        }

        int temp = abs(x);

        int res = 0;
        while(temp){
           if( res > INT_MAX/10 || res < INT_MIN/10){
               return 0;
           }
           res = (res*10 + temp%10);
           temp/=10;
        }

        if(sign){
            return (-res);
        }
        return res;
    }
};