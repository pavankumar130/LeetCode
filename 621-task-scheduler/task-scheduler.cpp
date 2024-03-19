class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        for(auto it:tasks){
            mp[it]++;
        }
        priority_queue<int>pq;
        for(auto it:mp){
           pq.push(it.second);
        }
        int res=0;
        while(!pq.empty()){
            int t=0;
            vector<int>temp;
            for(int i=0;i<=n;i++){
                if(!pq.empty()){
                    temp.push_back(pq.top()-1);
                    pq.pop();
                    t++;
                }
            }
            for(auto it:temp){
                if(it){
                    pq.push(it);
                }
            }
            if(pq.empty()){
                res+=t;
            }
            else{
                res+=n+1;
            }
        }
        return res;
    }
};