class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int res = 0;

        for(int i = 0; i < n; i++){
            map<int,int>mp;

            for(int j = i; j < n; j++){
                mp[s[j]]++;

                int num = mp.begin()->second;
                bool flag = false;
                for(auto it : mp){
                    if(it.second != num){
                        flag = true;
                        break;
                    }
                }

                if(!flag){
                    res = max(res, j - i + 1);
                }
            }
        }

        return res;
    }
};