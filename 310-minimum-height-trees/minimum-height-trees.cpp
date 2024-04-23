class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1){
            return {0};
        }

        vector<int>adj[n];
        vector<int>degree(n, 0);

        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            degree[u]++;
            degree[v]++;
        }

        queue<int>q;

        for(int i = 0; i < n; i++){
            if(degree[i] == 1){
                q.push(i);
            }
        }

        int rem = n;

        while(rem > 2){
            int size = q.size();
            rem -= size;
            for(int i = 0; i < size; i++){
                int node = q.front();
                q.pop();
                for(int it: adj[node]){
                    if(--degree[it] == 1){
                        q.push(it);
                    }
                }
            }
        }

        vector<int>res;
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};