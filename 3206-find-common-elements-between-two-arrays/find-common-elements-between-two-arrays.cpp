class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res(2,0);

        unordered_map<int,int>mp1;
        for(int i=0; i<nums2.size(); i++){
            mp1[nums2[i]]++;
        }
        
        unordered_map<int,int>mp2;
        for(int i=0; i<nums1.size(); i++){
            mp2[nums1[i]]++;
        }
         
        for(int i=0; i<nums1.size(); i++){
           if(mp1.find(nums1[i]) != mp1.end()){
               res[0]++;
           }
        }

        for(int i=0; i<nums2.size(); i++){
           if(mp2.find(nums2[i]) != mp2.end()){
               res[1]++;
           }
        }

        return res;
    }
};