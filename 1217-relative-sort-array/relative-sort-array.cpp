class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>mp;
        map<int,int>mp1;
        vector<int>arr;

        for(auto it: arr2){
            mp1[it]++;
        }

        for(auto it: arr1){
            if(mp1.find(it) == mp1.end()){
                arr.push_back(it);
            }
            else{
                mp[it]++;
            }
        }

        sort(arr.begin(), arr.end());

        vector<int>res;
        for(int i = 0; i < arr2.size(); i++){
            if(mp.find(arr2[i]) != mp.end()){
                for(int ind = 0; ind < mp[arr2[i]]; ind++){
                    res.push_back(arr2[i]);
                }
            }
        }

        for(int i = 0; i < arr.size(); i++){
            res.push_back(arr[i]);
        }

        return res;
    }
};