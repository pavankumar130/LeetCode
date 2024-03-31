class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drinkcnt = 0, emptybottles = 0;

        while(numBottles > 0 || emptybottles >= numExchange){
            if(emptybottles >= numExchange){
                emptybottles -= numExchange;
                numExchange++;
                numBottles++;
            }

            drinkcnt += numBottles;
            emptybottles += numBottles;
            numBottles = 0;
        }

        return drinkcnt;
    }
};