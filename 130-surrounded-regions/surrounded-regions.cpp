class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        queue<pair<int,int>>q;
        for(int j=0;j<m;j++){
            if(board[0][j] == 'O'){
               board[0][j]='*';
               q.push({0,j}); 
            }
            if(board[n-1][j] == 'O'){
                board[n-1][j]='*';
                q.push({n-1,j});
            }
        }
        for(int i=0;i<n;i++){
            if(board[i][0] == 'O'){
                board[i][0]='*';
                q.push({i,0});
            }
            if(board[i][m-1] == 'O'){
                board[i][m-1]='*';
                q.push({i,m-1});
            }
        }

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int row=r+dr[i];
                int col=c+dc[i];
                if(row >=0 && row<n && col>=0 && col<m && board[row][col] == 'O'){
                    board[row][col]='*';
                    q.push({row,col});
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == '*'){
                    board[i][j]='O';
                }
                else{
                    board[i][j]='X';
                }
            }
        }
    }
};