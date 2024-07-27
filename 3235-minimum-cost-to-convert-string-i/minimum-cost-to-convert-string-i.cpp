class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
        int n = original.size();
        
        vector<vector<long long>>graph(26,vector<long long>(26,1e9));
        
        for(int i=0; i<n; i++){
            graph[original[i]-'a'][changed[i]-'a'] = min(graph[original[i]-'a'][changed[i]-'a'],(long long)cost[i]);
        }
        
        for(int k = 0; k < 26; k++){
            for(int i = 0; i< 26; i++){
                for(int j = 0; j < 26; j++){
                    if( graph[i][j] > (long long)(graph[i][k]+graph[k][j] ) ){
                        graph[i][j] = (long long)(graph[i][k]+graph[k][j]);
                    }
                }
            }
        }
        
        long long res = 0;
        for(int i=0; i<source.length(); i++){
            int a = source[i]-'a';
            int b = target[i]-'a';
            if(a != b){
                if(graph[a][b] == 1e9){
                    return -1;
                }  
                res = (long long)(res + graph[a][b]);
            }
        }
        return res;
    }
};