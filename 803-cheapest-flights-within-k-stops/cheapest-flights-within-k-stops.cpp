class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];

        for(int i = 0; i < flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int cost = flights[i][2];
            adj[u].push_back({v,cost});
        }

        vector<int>dis(n,1e9);
        queue<pair<int,pair<int,int>>>q;
        dis[src] = 0;
        q.push({0,{src,0}});

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int steps = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(steps > k){
                continue;
            }

            for(auto i:adj[node]){
                int adjnode = i.first;
                int edgecost = i.second;

                if(cost + edgecost < dis[adjnode] && steps <= k){
                    dis[adjnode] = cost + edgecost;
                    q.push({steps + 1, {adjnode, cost + edgecost}});
                }
            }
        }

        if(dis[dst] == 1e9){
            return -1;
        }
        return dis[dst];
    }
};