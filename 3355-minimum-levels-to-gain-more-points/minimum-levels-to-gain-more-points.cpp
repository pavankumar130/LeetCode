class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n = possible.size();
        for(int i = 0; i < n; i++){
            if(possible[i] == 0){
                possible[i] = -1;
            }
        }

        vector<int>sufix(n, 0);
        sufix[n-1] = possible[n-1];
        for(int i = n-2; i >= 0; i--){
            sufix[i] = sufix[i + 1] + possible[i];
        }

        int curr = possible[0];
        for(int i = 1; i < n; i++){
            if(curr > sufix[i]){
                return i;
            }
            curr += possible[i];
        }

        return -1;

    }
};