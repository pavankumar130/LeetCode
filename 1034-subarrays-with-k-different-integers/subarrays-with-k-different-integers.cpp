class Solution {
public:
    int solve(vector<int>& arr, int k){
        int i=0;
        int j=0;
        int count=0;
        map<int,int>mp;
        while(i<arr.size()){
            mp[arr[i]]++;
            while(mp.size() > k){
                mp[arr[j]]--;
                if(mp[arr[j]] == 0){
                    mp.erase(arr[j]);
                }
                j++;
            }
            count+=(i-j+1);
            i++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};