class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<int>dist(n, 1e9);
        dist[0] = 0;

        vector<vector<pair<int,int>>> adj(n);

        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, 2*w});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>>q;
        q.push({0, 0});

        while(q.size()){
            int node = q.top().second;
            int d = q.top().first;
            q.pop();

            if(d > dist[node]){
                continue;
            }

            for(auto it: adj[node]){
                int wt = it.second;
                int new_node = it.first;

                if(dist[new_node] > dist[node] + wt){
                    dist[new_node] = dist[node] + wt;
                    q.push({dist[new_node], new_node});
                }
            }
        }

        if(dist[n - 1] == 1e9){
            return -1;
        }
        return dist[n - 1];
    }
};