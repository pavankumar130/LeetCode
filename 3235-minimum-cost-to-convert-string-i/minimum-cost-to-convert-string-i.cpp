class Solution {
    void solve(int source, vector<pair<int,int>> adj[], vector<vector<int>>&dis){
        dis[source][source] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>>q;
        q.push({0, source});

        while(q.size()){
            int node = q.top().second;
            q.pop();

            for(auto it: adj[node]){
                int new_node = it.second;
                int weight = it.first;

                if(dis[source][new_node] > dis[source][node] + weight){
                    dis[source][new_node] = dis[source][node] + weight;
                    q.push({dis[source][new_node], new_node});
                }
            }
        }
    }
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<pair<int,int>>adj[26];

        for(int i = 0; i < original.size(); i++){
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            adj[u].push_back({cost[i], v});
        }

        vector<vector<int>>dis(26, vector<int>(26, 1e9));

        for(int i = 0; i < 26; i++){
            solve(i, adj, dis);
        }

        long long cst = 0;

        for(int i = 0; i < source.size(); i++){
            if(source[i] == target[i]){
                continue;
            }

            int u = source[i] - 'a';
            int v = target[i] - 'a';

            if(dis[u][v] != 1e9){
                cst += dis[u][v];
            }
            else{
                return -1;
            }
        }

        return cst;
    }
};