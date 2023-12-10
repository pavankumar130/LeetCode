class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        int n = variables.size();
        vector<int>res;

        for(int i=0; i<n; i++){
            int m=variables[i][0];
            int b=variables[i][1];
            int c=variables[i][2];
            int d=variables[i][3];

            int n1 = 1;
            for(int j=0; j<b; j++){
                n1 = (n1*m)%10;
            }

            int n2=1;
            for(int j=0; j<c; j++){
                n2 = (n2*n1)%d;
            }

            if(n2 == target){
                res.push_back(i);
            }
        }
      return res;
    }
};