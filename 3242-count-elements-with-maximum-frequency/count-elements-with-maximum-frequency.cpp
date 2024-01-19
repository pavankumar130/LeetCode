class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int>mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }

        int maxi = 0;
        for(auto it:mp){
            maxi = max(maxi,it.second);
        }
        int cnt = 0;
        for(auto it:mp){
            if(maxi == it.second){
                cnt++;
            }
        }

        return (maxi*cnt);
    }
};