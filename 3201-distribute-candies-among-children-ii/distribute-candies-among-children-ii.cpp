class Solution {
public:
    long long distributeCandies(int candies, int limit) {
        if(3*limit<candies) return 0;
        long long op=0;
        for(int i=0;i<=limit;i++){
            long long leftCandies=candies-i;
            // Not Possible to distribute
            if(leftCandies<0){
              continue;
            } 
            if(leftCandies>2*limit){
                continue;
            }
            
            
            if(leftCandies<=limit){
                op+=leftCandies+1;
                continue;
            }
            if(leftCandies<=2*limit){
                op+=(2*limit-leftCandies)+1;
                continue;
            }
        }
        return op;
    }
};