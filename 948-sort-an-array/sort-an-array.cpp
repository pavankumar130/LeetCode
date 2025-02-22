class Solution {
    void mergesort(int s, int m, int e, vector<int>&nums){
        vector<int>temp;

        int i = s;
        int j = m + 1;

        while(i <= m && j <= e){
            if(nums[i] < nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }

        while(i <= m){
            temp.push_back(nums[i]);
            i++;
        }
        while(j <= e){
            temp.push_back(nums[j]);
            j++;
        }

        int k = 0;
        for(int i = s; i <= e; i++){
            nums[i] = temp[k];
            k++;
        }

    }

    void merge(int s, int e, vector<int>&nums){
        if(s >= e){
            return;
        }

        int m = (s + e) / 2;

        merge(s, m, nums);
        merge(m + 1, e, nums);
        mergesort(s, m, e, nums);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        merge(0, nums.size()-1, nums);
        return nums;
    }
};