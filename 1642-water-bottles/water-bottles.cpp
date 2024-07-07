class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total = numBottles;
        int initial = numBottles;

        int cnt = 0;
        while(initial != 0){
            initial--;
            cnt++;

            if(cnt == numExchange){
                cnt = 0;
                total++;
                initial++;
            }
        }

        return total;
    }
};