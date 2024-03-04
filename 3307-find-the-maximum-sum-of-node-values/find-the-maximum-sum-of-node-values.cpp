class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum = 0, cnt = 0, temp = INT_MAX;

        for(auto it: nums){
            if((it ^ k) > it){
                sum += (it ^ k);
                temp = min(temp, (long long)((it^k) - it));
                cnt++;
            }
            else{
                sum += it;
                temp = min(temp, (long long)(it - (it^k)));
            }
        }

        if(cnt % 2 == 0){
            return sum;
        }
        return sum - temp;
    }
};