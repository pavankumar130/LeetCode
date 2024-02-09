class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1),hash(n);
        int maxi=1;
        int ind=0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j] == 0 && dp[i] < 1+dp[j]){
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
            if(dp[i] > maxi){
                maxi=dp[i];
                ind=i;
            }
        }
        vector<int>res;
        res.push_back(nums[ind]);
        while(hash[ind] != ind){
            ind=hash[ind];
            res.push_back(nums[ind]);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};