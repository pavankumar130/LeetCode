class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>st,temp;

        for(auto it:nums1){
            temp.insert(it);
        }

        for(int i = 0; i < nums2.size(); i++){
            if(temp.find(nums2[i]) != temp.end()){
                st.insert(nums2[i]);
            }
        }

        vector<int>res(st.begin(),st.end());
        return res;
    }
};