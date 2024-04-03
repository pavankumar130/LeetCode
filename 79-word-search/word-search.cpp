class Solution {
public:
bool help(vector<vector<char>>& board, string word, int i, int j, int ind, int n, int m){
    if(ind == word.size()){
        return true;
    }
    if(i<0 || j<0 || i>=n || j>=m || board[i][j] != word[ind] || board[i][j] == '!'){
        return false;
    }
    char c=board[i][j];
    board[i][j]='!';

    bool top=help(board,word,i-1,j,ind+1,n,m);
    bool right=help(board,word,i,j+1,ind+1,n,m);
    bool bottom=help(board,word,i+1,j,ind+1,n,m);
    bool left=help(board,word,i,j-1,ind+1,n,m);

    board[i][j]=c;
    return top||right||bottom||left;
}
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
          int index=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == word[index]){
                    if(help(board,word,i,j,index,n,m)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};