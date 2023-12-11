class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        long long res = 0;
        int maxi =0;
        for(int i=0; i<n; i++){
           maxi = max(maxi,nums[i]);
        }

        int i=0,j=0,count=0;

        while(j<n){
            if(nums[j] == maxi){
                count++;
            }
            while(count >= k){
                res +=n-j;
                if(nums[i] == maxi){
                    count--;
                }
                i++;
            }
            j++;
        }
        return res;
    }
};