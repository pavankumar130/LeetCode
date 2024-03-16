class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        
        vector<int>vis(n, 0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        long long total = 0;
        
        for(int i = 0; i < n; i++){
            pq.push({nums[i], i});
            total += nums[i];
        }
        
        vector<long long>res(m, 0);
        
        for(int i = 0; i < m; i++){
            if(total == 0 || pq.size() == 0){
                break;
            }
            
            if(vis[queries[i][0]] == 0){
                vis[queries[i][0]] = 1;
                total -= nums[queries[i][0]];
            }
            
            int cnt = queries[i][1];
            while(cnt  && pq.size() > 0){
                int val = pq.top().first;
                int ind = pq.top().second;
                pq.pop();
                if(vis[ind]){
                    continue;
                }
                total -= val;
                vis[ind] = 1;
                cnt--;
            }
            res[i] = total;
        }
        
        return res;
    }
};