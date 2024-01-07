class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();

        vector<unordered_map<long long, int>>mp(n);
        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){

                long long diff = (long long)nums[i]-(long long)nums[j];
                if(diff > INT_MAX || diff < INT_MIN){
                    continue;
                }

                if(mp[j].find(diff) != mp[j].end()){
                    ans += mp[j][diff];
                    mp[i][diff] += mp[j][diff];
                }

                mp[i][diff]+=1;
            }
        }
        return ans;
    }
};