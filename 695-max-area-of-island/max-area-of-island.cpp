class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        vector<vector<int>>vis(n,vector<int>(m,0));
        int res=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] || !grid[i][j]){
                    continue;
                }
                else{
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    vis[i][j]=1;
                    int island=0;

                    while(!q.empty()){
                        int row=q.front().first;
                        int col=q.front().second;
                        island++;
                        q.pop();

                        for(int ind=0; ind <4; ind++){
                            int drow=row+dr[ind];
                            int dcol=col+dc[ind];
                            if(drow >=0 && drow < n && dcol >=0 && dcol < m && !vis[drow][dcol] && grid[drow][dcol]){
                                vis[drow][dcol]=1;
                                q.push({drow,dcol});
                            }
                        }
                    }

                    res = max(res,island);
                }
            }
        }

        return res;
    }
};