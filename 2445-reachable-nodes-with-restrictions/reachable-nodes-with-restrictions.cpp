class Solution {
    void solve(int node, vector<int>adj[], vector<int>&vis){
        vis[node] = 1;

        for(auto it:adj[node]){
            if(vis[it] == 0){
                solve(it, adj, vis);
            }
        }
    }
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int>adj[n];

        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>vis(n, 0);

        for(int i = 0; i < restricted.size(); i++){
            vis[restricted[i]] = 2;
        }

        solve(0, adj, vis);

        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(vis[i] == 1){
                cnt++;
            }
        }
        return cnt;
    }
};