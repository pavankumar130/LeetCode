class Solution {
public:
    int pivotInteger(int n) {
        if(n == 1){
            return 1;
        }

        int res = -1;
        int total = (n *(n+1))/2;

        for(int i = 1; i <= n; i++){
            int sum = 0;
            for(int j = 1; j <= i; j++){
                sum += j;
            }
            if(sum == (total - sum + i)){
                return i;
            }
        }
        return res;
    }
};