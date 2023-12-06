class Solution {
public:
    int totalMoney(int n) {
        
        int res = 0;
        int money = 1;
        int count = 1;
        for(int i=1; i<=n; i++){
            if(i != 1 && (i)%7 == 1){
                count++;
                money = count;
            }
            cout<<money<<" ";
            res+=money;
            money++;
        }
        return res;
    }
};