class Solution {
public:
int rev(int n){
    int sum=0;
    while(n){
        sum =(sum*10)+(n%10);
        n/=10;
    }
    return sum;
}
    int countNicePairs(vector<int>& nums) {
        int mod=1e9+7;
        unordered_map<int,int>mp;
        int pairs=0;

        for(int i=0; i<nums.size(); i++){

            int num = nums[i]-rev(nums[i]);
            if(mp.find(num) != mp.end()){
                pairs = (pairs+mp[num])%mod;
            }
            mp[num]++;
        }
        return pairs;
    }
};