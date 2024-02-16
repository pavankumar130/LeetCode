class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        if(arr.size() == 1){
            if(arr[0] == k){
                return 0;
            }
            return 1;
        }
        unordered_map<int,int>mp;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            mp[arr[i]]++;
        }
        vector<int>temp;
        for(auto it:mp){
            temp.push_back(it.second);
        }

        sort(temp.begin(),temp.end());
        int res = temp.size();
        for(int i = 0; i < temp.size(); i++){
            if(temp[i] <= k){
                k -= temp[i];
                res--;
            }
            else{
                break;
            }
        }
        return res;
    }
};