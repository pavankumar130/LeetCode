class Solution {
    bool isprime(int num){
        if(num == 1){
            return false;
        }
        
        for(int i = 2; i*i <= num; i++){
            if(num%i == 0){
                return false;
            }
        }
        return true;
    }
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int first = -1;
        int last = -1;

        for(int i = 0; i < nums.size(); i++){
            if(isprime(nums[i]) ){
                if(first == -1){
                    first = i;
                    last = i;
                }
                else{
                    last = i;
                }
            }
        }

        return (last - first);
    }
};