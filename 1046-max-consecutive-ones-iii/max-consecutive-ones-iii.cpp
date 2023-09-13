class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=0;
        int maxi=0;
        int count=0;
        while(j<n){
            if(nums[j] == 1){
                j++;
            }
            else if(nums[j] == 0 && count < k){
                count++;
                j++;
            }
            else{
                while(count >= k){
                    if(nums[i] == 1){
                        i++;
                    }
                    else{
                        i++;
                        count--;
                    }
                }
            }
            maxi=max(maxi,j-i);
        }
        return maxi;
    }
};