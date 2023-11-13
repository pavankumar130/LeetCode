class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>inorder(n);
        for(int i=0; i<edges.size(); i++){
            int u=edges[i][0];
            int v=edges[i][1];
            inorder[v]++;
        }

        int res=-1;
        for(int i=0; i<n; i++){
            if(inorder[i] == 0){
                if(res == -1){
                    res=i;
                }
                else{
                    return -1;
                }
            }
        }
        return res;
    }
};