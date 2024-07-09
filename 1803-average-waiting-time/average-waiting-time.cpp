class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();

        long long initial = customers[0][0] + customers[0][1];
        long long late = initial - customers[0][0];
        // cout<<initial<<" ";

        for(int i = 1; i < n; i++){
            if(initial < customers[i][0]){
                initial = (customers[i][0] + customers[i][1]);
            }
            else{
                initial +=  customers[i][1];
            }

            late += (initial - customers[i][0]);
            // cout<<initial<<" ";
        }
        return double(late * 1.0/n);
    }
};