class Solution {
    int solve(int num){
        int cnt = 2;
        int res = num + 1;

        for(int i = 2; i * i <= num; i++){
            if(num % i == 0){
                if(i * i == num){
                    cnt ++;
                    res += i;
                }
                else{
                    cnt += 2;
                    res = res + i + (num/i);
                }
            }
        }

        if(cnt == 4){
            return res;
        }
        return 0;
    }
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            res = (res + solve(nums[i]));
        }

        return res;
    }
};