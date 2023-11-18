class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int left=0;
        int ans=0;
        long long curr=0;

        for(int i=0; i<n; i++){
            long long target = nums[i];
            curr+=nums[i];

            while((i-left+1)*target - curr > k){
                curr-=nums[left];
                left++;
            }
            ans=max(ans, i-left+1);
        }
        return ans;
    }
};