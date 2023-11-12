class Solution {
public:
    long long distributeCandies(int n, int limit) {
        
        long long ans = 0;
        for(int i=0;i<=min(n,limit);i++){
            int rem = n - i;
            if(2*limit < rem){
                continue;
            }
            int y = rem-min(limit,rem);
            ans = ans + (min(rem,limit)-y+1);
        }
        return ans ;
        
    }
};