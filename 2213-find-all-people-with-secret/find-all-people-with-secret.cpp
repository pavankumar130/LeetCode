class Disjoint{
    vector<int>parent,size;
    public:
    Disjoint(int n){
        parent.resize(n+1);
        size.resize(n+1);

        for(int i = 0; i <= n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUpar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUpar(parent[node]);
    }

    void UnionBySize(int u, int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if(ulp_u == ulp_v){
            return;
        }

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

    void reset(int x){
        parent[x] = x;
        size[x] = 1;
    }
};

class Solution {
    static bool cmp(vector<int>&a, vector<int>&b){
        return a[2] < b[2];
    }
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        
        sort(meetings.begin(), meetings.end(), cmp);

        int meeting_no = meetings.size();
        Disjoint ds(n);
        ds.UnionBySize(0, firstPerson);

        int ind = 0;
        while(ind < meeting_no){
            int time = meetings[ind][2];
            int start = ind;
            while(ind < meeting_no && time == meetings[ind][2]){
                ds.UnionBySize(meetings[ind][0], meetings[ind][1]);
                ind++;
            }

            while(start < ind){
                if(ds.findUpar(meetings[start][0]) != ds.findUpar(0)){
                    ds.reset(meetings[start][0]);
                    ds.reset(meetings[start][1]);
                }
                start++;
            }
        }

        vector<int>ans;

        for(int i = 0; i < n; i++){
            if(ds.findUpar(i) == ds.findUpar(0)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};