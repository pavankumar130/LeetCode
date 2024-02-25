class Disjoint{
    public:
   vector<int>parent,size;
   Disjoint(int n){
       parent.resize(n);
       size.resize(n);

       for(int i = 0; i < n; i++){
           parent[i] = i;
           size[i] = 1;
       }
   }

   int FindUpar(int node){
       if(node == parent[node]){
           return node;
       }
       return parent[node] = FindUpar(parent[node]);
   }

   void UnionBySize(int u, int v){
       int ulp_u = FindUpar(u);
       int ulp_v = FindUpar(v);

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
};

class Solution {
public:
    map<int,vector<int>>mp;
    void primeFactors(int n, int ind){
        
        if(n%2 == 0){
            mp[2].push_back(ind);
        }
        while(n%2 == 0){
            n/= 2;
        }

        for(int i = 3; i <= sqrt(n); i+=2){
            if(n%i == 0){
                mp[i].push_back(ind);
            }
            while(n%i == 0){
                n/=i;
            }
        }
        if(n > 2){
            mp[n].push_back(ind);
        }
    }

    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        Disjoint ds(n);

        for(int i = 0; i < n; i++){
            primeFactors(nums[i], i);
        }

        for(auto it:mp){
            vector<int> ids = it.second;
            
            for(int i = 1; i < ids.size(); i++){
                ds.UnionBySize(ids[0], ids[i]);
            }
        }

        set<int>par;
        for(int i = 0; i < n; i++){
            par.insert(ds.FindUpar(i));
        }

        return par.size() == 1;
    }
};