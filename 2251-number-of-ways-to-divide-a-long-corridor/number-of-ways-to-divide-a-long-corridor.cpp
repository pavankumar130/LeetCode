class Solution {
public:
    int numberOfWays(string corridor) {
        int n=corridor.size();
        int seats=0;
        int mod=1e9+7;
        for(int i=0; i<n; i++){
            if(corridor[i] == 'S'){
                seats++;
            }
        }

        if(seats == 0 || seats % 2 != 0){
            return 0;
        }
       
       long long res = 1;
       int c=0;

       for(int i=0; i<n; i++){
           if(corridor[i] == 'S'){
               c++;
           }
           if(c == 2){
               int temp=1;
               i++;
               while(i < n && corridor[i] == 'P'){
                   i++;
                   temp++;
               }
               if(i == n){
                  break;
                }
               res = (res*temp)%mod;
               c =0;
               i--;
           }
       }
      return (int)res;
    }
};