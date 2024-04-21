class Solution {
    bool solve(int node, vector<int>adj[], vector<int>&vis, int dest){
        if(node == dest){
            return true;
        }

        vis[node] = true;
        
        for(auto it:adj[node]){
            if(!vis[it]){
                if(solve(it, adj, vis, dest)){
                    return true;
                }
            }
        }

        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>adj[n];

        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n, 0);
        return solve(source, adj, vis, destination);
    }
};