class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int res = 0;
        int num = 0;

        for(int i = 0; i < dimensions.size(); i++){
            int temp = (dimensions[i][0]*dimensions[i][0] + 
                              dimensions[i][1]*dimensions[i][1]);

            if(num < temp){
                num = temp;
                res = 0;
            }
            if(num == temp){
                res = max(res,dimensions[i][0]*dimensions[i][1]);
            }
        }

        return res;
    }
};