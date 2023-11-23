class Solution {
public:
bool solve(vector<int>&nums, int l, int r){
    vector<int>temp;
    for(int i=l; i<=r; i++){
        temp.push_back(nums[i]);
    }

    sort(temp.begin(),temp.end());

    int diff = temp[1]-temp[0];

    for(int i=1; i<temp.size(); i++){
       if(temp[i]-temp[i-1] != diff){
           return false;
       }
    }
    return true;
}
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        vector<bool>res;
        int n=nums.size();
        int m=l.size();
        for(int i=0; i<m; i++){
           bool temp = solve(nums,l[i],r[i]);
           res.push_back(temp);
        }
        return res;
    }
};