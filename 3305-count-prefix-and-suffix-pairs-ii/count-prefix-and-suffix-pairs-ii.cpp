#define ll long long
class Trie{
    public:
    map<int,Trie*>mp;
    int cnt;
    Trie(){
        cnt = 0;
    }
};
class Solution {
 Trie* root;
public:
    Solution(){
        root = new Trie();
    }
    long long countPrefixSuffixPairs(vector<string>& words) {
        ll ans = 0;
        for(auto word: words){
            Trie* curr = root;
            int n = word.size();

            for(int i = 0; i < n; i++){
                int node = word[i]*128 + word[n-1-i];
                if(curr->mp.find(node) == curr->mp.end()){
                    curr->mp[node] = new Trie();
                }
                curr = curr->mp[node];
                ans += curr->cnt;
            }
            curr->cnt++;
        }
        return ans;
    }
};