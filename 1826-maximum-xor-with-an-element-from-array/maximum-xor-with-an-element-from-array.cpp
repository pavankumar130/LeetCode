class Solution {
    class Node{
        public:
        Node* children[2];
    };
    class Trie{
        private:
        Node * root;
        public:
        Trie(){
            root = new Node();
        }

        void put(int num){
            Node* node = root;
            for(int i=31; i>=0; i--){
                int bit = (num>>i)&1;
                if(!node->children[bit]){
                    node->children[bit] = new Node();
                }
                node = node->children[bit];
            }
        }

        int getMaxi(int num){
            Node* node = root;
            int maxi = 0;
            for(int i=31; i>=0; i--){
                int bit = (num >> i) & 1;
                if(node->children[1-bit]){
                    maxi = maxi|(1<<i);
                    node = node->children[1-bit];
                }
                else{
                    node = node->children[bit];
                }
            }
            return maxi;
        }
    };
    static bool comp(vector<int>a,vector<int>b){
        return (a[1]<b[1]);
    }
public:
    vector<int> maximizeXor(vector<int>& arr, vector<vector<int>>& queries) {
        sort(arr.begin(),arr.end());
        Trie trie;
        
        int j=0;
        for(int i=0; i<queries.size(); i++){
            queries[i].push_back(i);
        }
        sort(queries.begin(),queries.end(),comp);
        vector<int>res(queries.size());
        for(int i=0; i<queries.size(); i++){
            int x = queries[i][0];
            int idx = queries[i][2];
            int l = queries[i][1];

            while(j<arr.size() && arr[j]<=l){
                trie.put(arr[j++]);
            }
            if(j == 0){
                res[idx]=-1;
            }
            else{
                res[idx]=trie.getMaxi(x);
            }
        }
      return res;
    }
};