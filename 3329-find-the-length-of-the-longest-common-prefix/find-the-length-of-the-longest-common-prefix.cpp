class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        unordered_map<int,int>mp1,mp2;
        for(int i = 0; i < n; i++){
            int temp = arr1[i];
            while(temp){
                mp1[temp]++;
                temp/= 10;
            }
        }

        for(int i = 0; i < m; i++){
            int temp = arr2[i];
            while(temp){
                mp2[temp]++;
                temp/= 10;
            }
        }
        int res = 0;
        for(auto it:mp1){
            if(mp2.find(it.first) != mp2.end()){
                string s = to_string(it.first);
                res = max(res, (int)s.size());
            }
        }
        return res;
    }
};