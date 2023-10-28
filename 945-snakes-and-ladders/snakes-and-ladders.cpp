class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        int end=n*n;
        vector<int>vis(n*n+1, 0);
        vector<int>bd(n*n+1,-1);

        int rev=0, cnt=1;
        for(int i=n-1; i>=0; i--){
            if(rev){
                for(int j=n-1;j>=0;j--){
                    bd[cnt++]=board[i][j];
                }
            }
            else{
               for(int j=0;j<n;j++){
                   bd[cnt++]=board[i][j];
               } 
            }
            rev=!rev;
        }

        queue<pair<int,int>>q;
        q.push({1,0});
        while(!q.empty()){
            pair<int,int>curr=q.front();
            q.pop();
            if(curr.first == end){
                return curr.second;
            }

            for(int i=1;i<=6 && curr.first+i <=end;i++){
                if(vis[curr.first+i]){
                    continue;
                }
                if(bd[curr.first+i] == -1){
                    q.push({curr.first+i,curr.second+1});
                }
                else{
                    q.push({bd[curr.first+i],curr.second+1});
                }
                vis[curr.first+i]=1;
            }
        }
        return -1;
    }
};