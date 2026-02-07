class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int>counto(n + 1, 0);

        for(int i = 0; i < n; i++){
            if(s[i] == '0'){
                counto[i + 1] = 1;
            }
            counto[i + 1] += counto[i];
        }

        int mini = 1e9;

        for(int i = 0; i <= n; i++){
            int left1 = i - counto[i];
            int righto = counto[n] - counto[i];

            mini = min(mini, left1 + righto);
        }

        return mini;
    }
};