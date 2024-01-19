class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        set<int>s1,s2,common;

        for(int i = 0; i < n; i++){
            s1.insert(nums1[i]);
        }

        for(int i = 0; i < n; i++){
            s2.insert(nums2[i]);
            if(s1.find(nums2[i]) != s1.end()){
                common.insert(nums2[i]);
            }
        }

        int n1 = s1.size();
        int n2 = s2.size();
        int c = common.size();

        return min(n, min(n1-c,n/2)+min(n2-c,n/2)+c);
    }
};