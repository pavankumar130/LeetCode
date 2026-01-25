class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();

        sort(cost.begin(), cost.end());

        int sum = 0;
        int i = n - 1;

        while(i >= 0){
            if(i - 2 >= 0){
                sum += (cost[i] + cost[i - 1]);
                i -= 3;
            }
            else{
                sum += cost[i];
                i--;
            }
        }

        return sum;
    }
};