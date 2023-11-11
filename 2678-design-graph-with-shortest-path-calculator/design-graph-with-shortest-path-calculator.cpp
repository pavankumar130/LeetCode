class Graph {
    int Dijkstra(int src, int dest, vector<vector<pair<int,int>>>&adj){
        int n=adj.size();

        vector<int>dist(n,1e9);
        dist[src]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,src});

        while(!pq.empty()){
            int node=pq.top().second;
            int dis =pq.top().first;
            pq.pop();
            for(auto it:adj[node]){
                if(dist[it.first] > dis+it.second){
                    dist[it.first]=dis+it.second;
                    pq.push({dist[it.first], it.first});
                }
            }
        }
        return dist[dest];
    }
    vector<vector<pair<int,int>>>adj;
public:
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        int dist = Dijkstra(node1,node2,adj);

        if(dist == 1e9){
            return -1;
        }
        return dist;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */