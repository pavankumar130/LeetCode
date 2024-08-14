class Solution {
public:
void solve(int ind, int target, vector<int>&arr,vector<vector<int>>&ans,vector<int>&temp){
    if(ind > arr.size()){
        return;
    }
    if(target == 0){
        ans.push_back(temp);
        return;
    }
    for(int i = ind; i < arr.size(); i++){
        if(i>ind && arr[i] == arr[i-1]){
            continue;
        }
        if(target < arr[i]){
            break;
        }
        temp.push_back(arr[i]);
        solve(i+1, target-arr[i], arr, ans, temp);
        temp.pop_back();

    }
    return;
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0, target, candidates, ans, temp);
        return ans;
    }
};