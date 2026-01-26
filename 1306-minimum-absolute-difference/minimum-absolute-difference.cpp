class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>>res;

        int mini = INT_MAX;

        for(int i = 1; i < n; i++){
            if(mini > (arr[i] - arr[i - 1])){
                mini = (arr[i] - arr[i - 1]);
            }
        }

        for(int i = 1; i < n; i++){
            if(mini == (arr[i] - arr[i - 1])){
                res.push_back({arr[i - 1], arr[i]});
            }
        }

        return res;
    }
};