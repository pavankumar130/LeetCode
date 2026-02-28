class Solution {
public:
    const int mod = 1e9 + 7;
    long long fast(long long a, long long b) {
        long long ans = 1;

        while (b > 0) {
            if (b & 1) {
                ans = (ans * 1LL * a) % mod;
            }

            a = (a * a) % mod;
            b = b >> 1;
        }

        return ans;
    }

    int solve(int n) {

        for (int i = 31; i >= 0; i--) {
            if ((1 << i) & n) {
                return i + 1;
            }
        }

        return -1;
    }
    int concatenatedBinary(int n) {

        long long int ans = n;
        int bits = solve(n);

        for (int i = n - 1; i >= 1; i--) {

            int val = fast(2LL, bits);
            ans = (ans + (i * 1LL * val) % mod) % mod;
            bits += solve(i);
        }

        return ans;
    }
};