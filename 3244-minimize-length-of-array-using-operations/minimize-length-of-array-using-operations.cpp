class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int cnt = 1;
        int gcd = INT_MAX;

        for(int i = 1; i < n; i++){
            gcd = min(gcd, __gcd(nums[i],nums[i-1]));

            if(gcd < nums[0]){
                return 1;
            }
            if(nums[i] == nums[0]){
                cnt++;
            }
        }

        return (ceil(cnt/(2*1.0)));
    }
};