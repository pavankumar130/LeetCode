class Solution {

    vector<vector<int>>adj;
    vector<int>counter, res;

    void dfs(int i, int par = -1 ){

        for(auto it: adj[i]){

            if(it == par){
                continue;
            }

            dfs(it, i);
            counter[i] += counter[it];
            res[i] += res[it] + counter[it];
        }

        counter[i] += 1;
    }

    void dfs2(int i, int n, int p = -1){
        for(auto it: adj[i]){
            if(it == p){
                continue;
            }

            res[it] = res[i] - counter[it] + n - counter[it];
            dfs2(it, n, i);
        }
    }

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        res.resize(n);
        counter.resize(n);

        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0);
        dfs2(0, n);
        return res;
    }
};