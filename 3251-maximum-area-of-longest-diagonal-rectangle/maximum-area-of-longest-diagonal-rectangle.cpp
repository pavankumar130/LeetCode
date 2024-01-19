class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int res = 0, maxdia = 0;

        for(auto it:dimensions){
            int w = it[0], l = it[1], dia = (w*w + l*l);
            if(maxdia < dia){
                maxdia = dia;
                res = 0;
            }
            if(dia == maxdia){
                res = max(res, w*l);
            }
        }
        return res;
    }
};