class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int cnt = 0;

        for(int i = 0; i < n - 1; i++){
            int xorA = 0;
            for(int j = i + 1; j < n; j++){
                xorA ^= arr[j - 1];

                int xorB = 0;
                for(int k = j; k < n; k++){
                    xorB ^= arr[k];
                    if(xorA == xorB){
                        cnt++;
                    }
                }
            }
        }

        return cnt;
    }
};