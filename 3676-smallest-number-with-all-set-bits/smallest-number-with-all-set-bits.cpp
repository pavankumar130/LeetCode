class Solution {
public:
    int smallestNumber(int n) {
        int num = 2;

        while(num <= n){
            num = (num * 2);
        }

        return num - 1;
    }
};