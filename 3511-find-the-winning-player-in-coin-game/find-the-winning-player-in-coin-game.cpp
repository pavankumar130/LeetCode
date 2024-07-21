class Solution {
public:
    string losingPlayer(int x, int y) {
        int minturn = min(x, y/4);

        if(minturn%2 != 0){
            return "Alice";
        }
        return "Bob";
    }
};