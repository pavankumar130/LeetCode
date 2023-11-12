class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {

         if(source == target){
             return 0;
         }

        unordered_map<int,vector<int>>adj;
        for(int i=0; i<routes.size(); i++){
            for(auto it:routes[i]){
                adj[it].push_back(i);
            }
        }

        queue<int>q;
        unordered_set<int>st;
        for(auto it:adj[source]){
            q.push(it);
            st.insert(it);
        }
        
        int buscount=1;
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){

                int route =q.front();
                q.pop();

                for(auto stop:routes[route]){

                    if(stop == target){
                        return buscount;
                    }
                    
                    for(auto it:adj[stop]){
                        if(st.count(it) == 0){
                            st.insert(it);
                            q.push(it);
                        }
                    }
                }
            }
            buscount++;
        }
        return -1;
    }
};