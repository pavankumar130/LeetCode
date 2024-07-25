class Solution {
public:
    void merge(vector<int>&arr, int l, int mid, int r){
        int i = l;
        int j = mid+1;
        vector<int>temp;
        while(i <= mid && j <= r){
            if(arr[i] <= arr[j]){
                temp.push_back(arr[i]);
                i++;
            }
            else{
                temp.push_back(arr[j]);
                j++;
            }
        }
        while(i <= mid){
            temp.push_back(arr[i]);
            i++;
        }
        while(j <= r){
            temp.push_back(arr[j]);
            j++;
        }

        int ind=0;
        for(int i = l;i <= r; i++){
            arr[i] = temp[ind];
            ind++;
        }
        temp.clear();
    }
    void mergesort(vector<int>&arr, int l, int r){
        if( l == r){
            return;
        }
        int mid = (l + r)/2;
        mergesort(arr, l, mid);
        mergesort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergesort(nums, 0, n-1);
        return nums;
    }
};