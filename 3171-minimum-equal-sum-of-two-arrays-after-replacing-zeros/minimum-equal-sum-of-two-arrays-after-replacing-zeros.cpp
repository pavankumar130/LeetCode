class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1=0;
        long long sum2=0;
        int c1=0;
        int c2=0;
        for(int i=0; i<nums1.size(); i++){
            sum1+=nums1[i];
            if(nums1[i] == 0){
               c1++;
            }
        }

        for(int i=0; i<nums2.size(); i++){
            sum2+=nums2[i];
            if(nums2[i] == 0){
               c2++;
            }
        }

        if(c1 == 0 && sum1 < sum2+c2){
            return -1;
        }
        if(c2 == 0 && sum2 < sum1+c1){
            return -1;
        }

        return max(sum1+(long long)c1, sum2+(long long)c2);
    }
};