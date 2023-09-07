class Solution {
public:
    int reachNumber(int target) {
        target=abs(target);
        int sum=0,mov=0,i=1;
        while(true){
            sum+=i;
            i++;
            mov++;
            if(sum == target){
                return mov;
            }
            if(sum > target &&(sum-target)%2 ==0 ){
                return mov;
            }
        }
        return mov;
    }
};