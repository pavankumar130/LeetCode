class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string, int>mp;

        for(auto it: arr){
            mp[it]++;
        }

        int cnt = 0;

        for(int i = 0; i < arr.size(); i++){
            
            if(cnt < k && mp[arr[i]] == 1){
                cnt++;
            }

            if(cnt == k && mp[arr[i]] == 1){
                return arr[i];
            }
        }

        return "";
    }
};