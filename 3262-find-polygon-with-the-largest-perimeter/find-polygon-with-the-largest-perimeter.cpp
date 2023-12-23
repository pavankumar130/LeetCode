class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        vector<long long>prefix;
        long long sum = 0;
        for(int i=0; i<n; i++){
            prefix.push_back(sum);
            sum+=nums[i];
        }
        for(int i=n-1; i>=2; i--){
            if(nums[i] < prefix[i]){
                return (prefix[i]+(long long)nums[i]);
            }
        }
        return -1;
    }
};