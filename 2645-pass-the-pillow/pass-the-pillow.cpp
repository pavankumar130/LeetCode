class Solution {
public:
    int passThePillow(int n, int time) {
        int dir = 1;
        int cnt = 0;
        int t = 1;

        while(cnt != time){
            while(cnt < time && dir == 1 && t < n){
                cnt++;
                t++;
            }
            if(t == n){
                dir = -1;
            }
            while(cnt < time && dir == -1 && t > 1){
                cnt++;
                t--;
            }
            if(t == 1){
                dir = 1;
            }
        }

        return t;
    }
};