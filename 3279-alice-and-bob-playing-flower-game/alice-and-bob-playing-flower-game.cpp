class Solution {
public:
    long long flowerGame(int n, int m) {
        long long oddN = n/2 + n%2;
        long long evenN = n/2;

        long long oddM = m/2 + m%2;
        long long evenM = m/2;

        return (oddN * evenM) + (evenN * oddM);
    }
};