class Solution {
public:
    int binaryGap(int n) {
        int prev = -1;
        int res = 0;

        int curr = 0;
        while(n){
            if(n % 2){
                if(prev == -1){
                    prev = curr;
                }

                res = max(res, curr - prev);
                prev = curr;
            }
            n /= 2;
            curr++;
        }

        return res;
    }
};