class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int n = s.size();
        int m = g.size();
        int res = 0;
        int j = 0;
        for(int i=0; i < m; i++){
            while(j < n){
                if(g[i] <= s[j]){
                    j++;
                    res++;
                    break;
                }
                j++;
            }
        }
        return res;
    }
};