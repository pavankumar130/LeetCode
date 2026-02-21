class Solution {
    bool is_prime(int num){
        if(num == 1){
            return false;
        }
        if(num == 2){
            return true;
        }

        for(int i = 2; i < num; i++){
            if(num % i == 0){
                return false;
            }
        }

        return true;
    }
public:
    int countPrimeSetBits(int left, int right) {
        vector<int>prime(33, 0);
        for(int i = 2; i <= 32; i++){
            if(is_prime(i)){
                prime[i] = 1;
            }
        }

        int res = 0;
        for(int i = left; i <= right; i++){
            int cnt = 0;
            int temp = i;
            while(temp){
                if(temp % 2){
                    cnt++;
                }

                temp /= 2;
            }

            if(prime[cnt]){
                res++;
            }
        }

        return res;
    }
};