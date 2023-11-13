class Solution {
public:
long long solve(int node, vector<int>&vis, vector<int>adj[],vector<int>&values){
   if(adj[node].size() ==1 && node != 0){
       return (long long)values[node];
   }
   vis[node]=1;
   long long s=0;
   for(auto it:adj[node]){
       if(!vis[it]){
          s+= solve(it,vis,adj,values);
       }
   }
   return min(s,(long long)values[node]);
}
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n=values.size();

        long long sum=0;
        for(auto it:values){
            sum+=it;
        }

        vector<int>adj[n];
        for(int i=0; i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[v].push_back(u);
            adj[u].push_back(v);
        }
        vector<int>vis(n,0);
        long long mini = solve(0,vis,adj,values);
        return sum-mini;
    }
};