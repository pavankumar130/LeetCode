class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n=nums.size();
        long long total = ((long long)n*(long long)(n-1))/2;

        long long good=0;
        unordered_map<int,int>mp;

        for(int i=0; i<n; i++){

            int num = (nums[i] - i);

            if(mp.find(num) != mp.end()){
                good+=mp[num];
            }

            mp[num]++;
        }

        return (total-good);
    }
};