class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int maxi=1;
        for(int i=0; i<n; i++){
            if(i == 0){
                arr[i]=1;
                continue;
            }
            if(arr[i]-arr[i-1] <= 1){
                maxi=max(maxi,arr[i]);
                continue;
            }
            arr[i]=arr[i-1]+1;
            maxi=max(maxi,arr[i]);
        }
        return maxi;
    }
};