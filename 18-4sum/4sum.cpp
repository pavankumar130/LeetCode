class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            for(int j=i+1;j<n;j++){
                if(j>i+1 && nums[j] == nums[j-1]){
                   continue;
                }
                int l=j+1;
                int h=n-1;
                while(l<h){
                    long long sum= (long long)nums[i]+(long long)nums[j]+(long long)nums[l]+(long long)nums[h];
                    if(sum > (long long)target){
                        h--;
                    }
                    else if(sum < (long long)target){
                        l++;
                    }
                    else{
                        res.push_back({nums[i],nums[j],nums[l],nums[h]});
                        l++;
                        h--;
                        while(l<h && nums[l] == nums[l-1]){
                            l++;
                        }
                        while(l<h && nums[h] == nums[h+1]){
                            h--;
                        }
                    }
                }
            }
        }
        return res;
    }
};