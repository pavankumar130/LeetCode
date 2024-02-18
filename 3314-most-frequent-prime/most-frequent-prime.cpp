class Solution {
    bool isprime(int n){
        if(n < 10){
            return false;
        }

        for(int i = 2; i*i <= n; i++){
            if(n%i == 0){
                return false;
            }
        }
        return true;
    }
public:
    int mostFrequentPrime(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        map<long long,long long>mp;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                
                // 1
                long long temp = mat[i][j];
                for(int k = i-1; k >= 0; k--){
                    temp *= 10;
                    temp += mat[k][j];
                    if(isprime(temp)){
                        mp[temp]++;
                    }
                }

                // 2
                temp = mat[i][j];
                for(int k = i-1, l = j+1;  k >= 0 && l < m; k--,l++){
                    temp*= 10;
                    temp += mat[k][l];
                    if(isprime(temp)){
                        mp[temp]++;
                    }
                }

                // 3
                temp = mat[i][j];
                for(int l = j+1; l < m; l++){
                    temp *= 10;
                    temp += mat[i][l];
                    if(isprime(temp)){
                        mp[temp]++;
                    }
                }
                
                // 4
                temp = mat[i][j];
                for(int k = i+1, l = j+1; k < n && l < m ; k++, l++){
                    temp *= 10;
                    temp += mat[k][l];
                    if(isprime(temp)){
                        mp[temp]++;
                    }
                }

                // 5
                temp = mat[i][j];
                for(int k = i+1; k < n; k++){
                    temp *= 10;
                    temp += mat[k][j];
                    if(isprime(temp)){
                        mp[temp]++;
                    }
                }

                // 6
                temp = mat[i][j];
                for(int k = i+1, l = j-1; k < n && l >= 0; k++,l--){
                    temp *= 10;
                    temp += mat[k][l];
                    if(isprime(temp)){
                        mp[temp]++;
                    }
                }

                // 7
                temp = mat[i][j];
                for(int l = j-1; l >= 0; l--){
                    temp *= 10;
                    temp += mat[i][l];
                    if(isprime(temp)){
                        mp[temp]++;
                    }
                }

                // 8
                temp = mat[i][j];
                for(int k = i-1, l = j-1; k >= 0 && l >= 0;  k--,l--){
                    temp *= 10;
                    temp += mat[k][l];
                    if(isprime(temp)){
                        mp[temp]++;
                    }
                }
            }
        }

        long long maxi = 0;
        long long ans = -1;

        for(auto it:mp){
            if(it.second == maxi){
                ans = max(ans, it.first);
            }
            else if(it.second > maxi){
                maxi = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};