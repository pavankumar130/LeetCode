class Solution {
public:
    int minOperations(int k) {
        if(k == 1){
            return 0;
        }

        int mini = k;

        for(int i = 1; i <= k; i++){

            int duplicate = ceil(k/(i * 1.0));

            mini = min(mini, (i - 2 + duplicate));
        }

        return mini;
    }
};