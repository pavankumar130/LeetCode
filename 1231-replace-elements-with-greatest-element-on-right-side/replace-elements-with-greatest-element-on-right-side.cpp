class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans;
        int maxi=-1;
        for(int i=n-1;i>=0;i--){
           ans.push_back(maxi);
           maxi=max(arr[i],maxi);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};