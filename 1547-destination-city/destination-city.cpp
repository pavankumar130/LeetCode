class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        
        int n=paths.size();

        for(int i=0; i<n; i++){
            string res=paths[i][1];
            bool flag=true;

            for(int j=0; j<n; j++){
                if(paths[j][0] == res){
                    flag = false;
                    break;
                }
            }

            if(flag){
                return res;
            }
        }
        return "";
    }
};