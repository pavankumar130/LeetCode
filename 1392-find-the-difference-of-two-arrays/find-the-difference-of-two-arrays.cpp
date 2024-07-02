class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>mp1, mp2;

        for(auto it: nums1){
            mp1[it]++;
        }

        for(auto it: nums2){
            mp2[it]++;
        }

        vector<int>arr1, arr2;

        for(auto it: mp1){
            if(mp2.find(it.first) == mp2.end()){
                arr1.push_back(it.first);
            }
        }

        for(auto it: mp2){
            if(mp1.find(it.first) == mp1.end()){
                arr2.push_back(it.first);
            }
        }

        return {arr1, arr2};
    }
};