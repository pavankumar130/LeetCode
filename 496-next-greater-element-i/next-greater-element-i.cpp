class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>mp;
        stack<int>st;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            if(!st.empty() && st.top() > nums2[i]){
                mp[nums2[i]]=st.top();
            }
            else{
                mp[nums2[i]]=-1;
            }
            st.push(nums2[i]);
        }
        vector<int>res(nums1.size());
        for(int i=0;i<nums1.size();i++){
            if(mp.find(nums1[i]) != mp.end()){
                res[i]=mp[nums1[i]];
            }
        }
        return res;
    }
};