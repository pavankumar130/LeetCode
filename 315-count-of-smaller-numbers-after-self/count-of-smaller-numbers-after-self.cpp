class Solution {
    void merge(vector<int>&res, vector<pair<int,int>>&arr, int low, int mid, int high){
        vector<pair<int,int>>temp(high - low + 1);

        int i = low, j = mid + 1;
        int k = 0;

        while(i <= mid && j <= high){
            if(arr[i].first <= arr[j].first){
                temp[k++] = arr[j++];
            }
            else{
                res[arr[i].second] += (high - j +1);
                temp[k++] = arr[i++];
            }
        }

        while(i <= mid){
            temp[k++] = arr[i++];
        }

        while(j <= high){
            temp[k++] = arr[j++];
        }

        for(int i = low; i <= high; i++){
            arr[i] = temp[i - low];
        }
    }
    void mergesort(vector<int>&res, vector<pair<int,int>>&arr, int low, int high){
        if(low >= high){
            return;
        }

        int mid = (low + high)/2;
        mergesort(res, arr, low, mid);
        mergesort(res, arr, mid+1, high);
        merge(res, arr, low, mid, high);
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int,int>>arr;

        for(int i = 0; i < n; i++){
            arr.push_back({nums[i], i});
        }

        vector<int>res(n,0);
        mergesort(res, arr, 0, n-1);
        return res;
    }
};