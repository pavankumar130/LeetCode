class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n);

        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                int num = nums[i];
                int cnt = 0;
                int ind = i;
                while(cnt != num){
                    ind++;
                    cnt++;
                    if(ind == n){
                        ind = 0;
                    }

                    res[i] = nums[ind];
                }
            }
            else if(nums[i] < 0){
                int num = abs(nums[i]);
                int cnt = 0;
                int ind = i;
                while(cnt != num){
                    ind--;
                    cnt++;
                    if(ind == -1){
                        ind = n-1;
                    }

                    res[i] = nums[ind];
                }
            }
            else{
                res[i] = nums[i];
            }
        }

        return res;
    }
};