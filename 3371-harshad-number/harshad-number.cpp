class Solution {
    int solve(int x){
        int sum = 0;
        while(x){
            sum += (x%10);
            x /= 10;
        }
        return sum;
    }
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int num = solve(x);

        if(x % num == 0){
            return num;
        }
        return -1;
    }
};