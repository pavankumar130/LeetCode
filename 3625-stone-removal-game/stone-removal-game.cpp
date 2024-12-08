class Solution {
public:
    bool canAliceWin(int n) {
        int cnt = 0;
        int num = 10;
        while(n >= num){
            n = (n - num);
            num--;
            cnt++;
        }

        return (cnt%2);
    }
};