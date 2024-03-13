class Solution {
public:
    int pivotInteger(int n) {
        if(n == 1){
            return 1;
        }

        int res = -1;

        for(int i = 1; i <= n; i++){
            int sum1 = 0;
            for(int j = 1; j <= i; j++){
                sum1 += j;
            }
            int sum2 = 0;
            for(int j = i; j <= n; j++){
                sum2 += j;
            }

            if(sum1 == sum2){
                return i;
            }
        }
        return res;
    }
};