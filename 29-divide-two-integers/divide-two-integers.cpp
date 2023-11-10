class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1){
            return INT_MAX;
        }
        if(dividend == INT_MIN && divisor == 1){
            return INT_MIN;
        }

        long dd = abs(dividend);
        long dv = abs(divisor);

        int res=0;

        while(dd >= dv){
            long sum=dv;
            int count=1;
            while(sum <= dd -sum){
                sum+=sum;
                count+=count;
            }
            res+=count;
            dd-=sum;
        }

        if( (dividend<0 && divisor>0) || (dividend>0 && divisor<0) ){
            res=-res;
        }
        return res;
    }
};