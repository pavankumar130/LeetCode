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
public:
   typedef pair<int, pair<int,int>> ppi;
    vector<int> maximizeXor(vector<int>& arr, vector<vector<int>>& queries) {
        vector<ppi> offlineQueries;
        Trie T;
        vector<int> output(queries.size(),0);
        //load all the queries into offline queries and sort the function
        for (int i = 0; i < queries.size(); i++){
            offlineQueries.push_back({queries[i][1],{queries[i][0],i}});
        }
        sort(offlineQueries.begin(),offlineQueries.end());
        sort(arr.begin(),arr.end()); //sort the array
        int iterator = 0;
        int i = 0;
        for (auto it: offlineQueries) {
            while (i < arr.size() && arr[i] <= it.first) {
              T.put(arr[i]);
              i++;
            }
            if (i != 0) output[it.second.second] = T.getMaxi(it.second.first);
            else output[it.second.second] = -1;
        }
        
        return output;
    }
};