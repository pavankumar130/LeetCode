class Solution {
public:
void solve(vector<vector<char>>& grid, vector<vector<int>>& vis, int i, int j, int n, int m){
    vis[i][j] = 1;

    int dr[]={-1,0,1,0};
    int dc[]={0,1,0,-1};
    for(int k=0;k<4;k++){
        int row=i+dr[k];
        int col=j+dc[k];
        if(row >= 0 && row<n && col>=0 && col<m && grid[row][col] == '1' && !vis[row][col]){
            solve(grid,vis,row,col,n,m);
        }
    }
}
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(!vis[i][j] && grid[i][j] == '1'){
                   solve(grid,vis,i,j,n,m);
                   count++;
               }
           }
        }
        return count;
    }
};