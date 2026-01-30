class Solution {
    void solve(int src, vector<vector<pair<int,int>>>& adj, vector<vector<long long>>& dist) {

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<> > pq;

        dist[src][src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[src][u]){
                continue;
            }

            for (auto &[v, w] : adj[u]) {
                if (dist[src][v] > d + w) {
                    dist[src][v] = d + w;
                    pq.push({dist[src][v], v});
                }
            }
        }
    }
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        unordered_map<string,int>mp;
        int node = 0;

        for(int i = 0; i < original.size(); i++){
            if(!mp.count(original[i])){
                mp[original[i]] = node++;
            }

            if(!mp.count(changed[i])){
                mp[changed[i]] = node++;
            }
        }

        vector<vector<pair<int,int>>> adj(node);

        for (int i = 0; i < original.size(); i++) {
            int u = mp[original[i]];
            int v = mp[changed[i]];
            adj[u].push_back({v, cost[i]});
        }

        vector<vector<long long>>dis(node, vector<long long>(node, 1e18));

        for(int i = 0; i < node; i++){
            solve(i, adj, dis);
        }

        unordered_set<int> lens;
        for(auto &s : original){
            lens.insert(s.size());
        }


        int n = source.size();
        vector<long long>dp(n + 1, 1e18);

        dp[n] = 0;

        for(int i = n - 1; i >= 0; i--){
            if(source[i] == target[i]){
                dp[i] = dp[i + 1];
            }

            for(int len : lens){
                int j = i + len - 1;
                if(j >= n){
                    continue;
                }

                string from = source.substr(i, len);
                string to = target.substr(i, len);

                if(!mp.count(from) || !mp.count(to)){
                    continue;
                }

                long long cst = dis[mp[from]][mp[to]];
                if(cst < 1e18){
                    dp[i] = min(dp[i], cst + dp[j + 1]);
                }
            }
        }

        if(dp[0] >= 1e18){
            return -1;
        }

        return dp[0];
    }
};