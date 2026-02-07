class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int>counta(n + 1, 0);

        for(int i = 0; i < n; i++){
            if(s[i] == 'a'){
                counta[i + 1] = 1; 
            }

            counta[i + 1] += counta[i];
        }

        int mini = 1e9;

        for(int i = 0; i <= n; i++){
            int leftb = i - counta[i];
            int righta = counta[n] - counta[i];

            mini = min(mini, (leftb + righta));
        }

        return mini;
    }
};