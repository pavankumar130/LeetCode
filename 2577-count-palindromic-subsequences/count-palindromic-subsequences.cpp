class Solution {
public:
int giverev(int x){
    if(x < 10){
        return 10*x;
    }
    return 10*(x%10)+x/10;
}
    int countPalindromes(string s) {
        int mod = 1e9+7;

        vector<long long>back(10,0);
        vector<long long>front(10,0);

        vector<long long>subfront(100,0);
        vector<long long>subback(100,0);

        for(int i=s.length()-1; i>=0; i--){
           int x=s[i]-'0';
           for(int j=0; j<10; j++){
               if(back[j] > 0){
                   subback[x*10+j]+=back[j];
               }
           }
           back[x]++;
        }

        long long ans=0;

        for(int i=0; i<s.length(); i++){
            int x=s[i]-'0';

            // Remove From Back
            back[x]--;
            for(int j=0; j<10; j++){
                if(back[j] > 0){
                    subback[x*10+j]-=back[j];
                }
            }

            // calculate palindrome with 5 length
           for(int j=0; j<100; j++){
               ans+= subfront[j]*subback[giverev(j)];
               ans%=mod;
           }
           
           //Add to front
           for(int j=0; j<10; j++){
               if(front[j] > 0){
                   subfront[10*j+x]+=front[j];
               }
           }
           front[x]++;
        }
        return ans;
    }
};