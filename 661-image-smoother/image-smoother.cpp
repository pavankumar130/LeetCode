class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n=img.size();
        int m=img[0].size();

        vector<vector<int>>res(n,vector<int>(m,0));

        int dr[]={-1,-1,-1,0,1,1,1,0};
        int dc[]={-1,0,1,1,1,0,-1,-1};

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int cnt = 1;
                int avg = img[i][j];
                for(int ind=0; ind<8; ind++){
                    int x = i+dr[ind];
                    int y = j +dc[ind];
                    if(x>=0 && x<n && y>=0 && y<m){
                        cnt++;
                        avg+=img[x][y];
                    }
                }
                res[i][j] = avg/cnt;
            }
        }
        return res;
    }
};