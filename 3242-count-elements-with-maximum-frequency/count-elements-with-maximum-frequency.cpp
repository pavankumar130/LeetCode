class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int>mp;

        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }

        vector<int>arr;
        for(auto it:mp){
            arr.push_back(it.second);
        }

        sort(arr.begin(),arr.end());
        int n = arr.size();
        int num = arr[n-1];
        int res = 0;
        for(int i = n-1; i>= 0;  i--){
            if(num != arr[i]){
                break;
            }
            res += num;
        }
        return res;
    }
};