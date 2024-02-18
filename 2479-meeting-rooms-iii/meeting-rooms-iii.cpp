class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int>roomcnt(n,0);
        set<int>st;
        priority_queue<pair<long,long>,vector<pair<long,long>>,greater<pair<long,long>>>pq;
        sort(meetings.begin(),meetings.end());

        int m = meetings.size();

        for(int i = 0; i < n; i++){
            st.insert(i);
        }

        for(int i = 0; i < m; i++){
            long start = meetings[i][0];
            long end = meetings[i][1];

            while(pq.size() > 0 && pq.top().first <= start){
                int room = pq.top().second;
                pq.pop();
                st.insert(room);
            }
            if(st.size() == 0){
                pair<long , long> p = pq.top();
                pq.pop();
                long diff = end - start;
                start = p.first;
                end = start + diff;
                st.insert(p.second);
            }

            auto it = st.begin();
            roomcnt[*it]++;
            pq.push({end,*it});
            st.erase(*it);
        }

        int ans = 0;
        int maxi = 0;
        for(int i = 0; i < n; i++){
            if(maxi < roomcnt[i]){
                maxi = roomcnt[i];
                ans = i;
            }
        }
        return ans;
    }
};