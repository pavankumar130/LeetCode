class Solution {
    unordered_map<int, vector<pair<int,int>> >mp;
    int ss, n, cnt;
    void dfs(int node, int par, int dis){
        if(dis%ss == 0){
            cnt++;
        }

        for(auto it:mp[node]){
            if(it.first != par){
                dfs(it.first, node, dis + it.second);
            }
        }
    }
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        n = edges.size() + 1;
        ss = signalSpeed;
        for(auto it: edges){
            mp[it[0]].push_back({it[1],it[2]});
            mp[it[1]].push_back({it[0],it[2]});
        }

        vector<int>res(n, 0);

        for(int i = 0; i < n; i++){
            int ans = 0, sum = 0;
            vector<int>temp;
            for(auto it: mp[i]){
                cnt = 0;
                dfs(it.first, i, it.second);
                temp.push_back(cnt);
                sum += cnt;
            }

            for(auto it: temp){
                ans += (sum - it)*it;
            }

            res[i] = ans/2;
        }

        return res;
    }
};