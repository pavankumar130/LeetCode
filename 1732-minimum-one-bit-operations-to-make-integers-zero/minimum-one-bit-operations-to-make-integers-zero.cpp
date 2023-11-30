class Solution {
public:
    int minimumOneBitOperations(int n) {
        vector<long long>f(32);
        f[0]=1;
        for(int i=1; i<31; i++){
            f[i]=(f[i-1]*2+1);
        }
        
        int res = 0;
        int plus = 1;

        for(int i=30; i>=0; i--){
            bool isset = (1<<i & n) != 0;

            if(!isset){
                continue;
            }

            if(plus){
                res+=f[i];
            }
            else{
                res-=f[i];
            }
            plus^=1;
        }
        return res;
    }
};