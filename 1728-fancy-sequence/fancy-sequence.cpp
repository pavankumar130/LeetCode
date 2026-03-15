class Fancy {
    vector<long long> arr;
    long long mul = 1;
    long long add = 0;
    const int MOD = 1e9 + 7;
    
    // Modular inverse for division (Fermat's little theorem)
    long long modPow(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp & 1) res = res * base % MOD;
            base = base * base % MOD;
            exp >>= 1;
        }
        return res;
    }
    
    long long modInv(long long x) {
        return modPow(x, MOD - 2);
    }

public:
    Fancy() {}
    
    void append(int val) {
        // Store the "un-transformed" value such that:
        // val = (stored * mul + add) % MOD
        // => stored = (val - add) / mul
        long long stored = (val - add + MOD) % MOD;
        stored = stored * modInv(mul) % MOD;
        arr.push_back(stored);
    }
    
    void addAll(int inc) {
        add = (add + inc) % MOD;
    }
    
    void multAll(int m) {
        mul = mul * m % MOD;
        add = add * m % MOD;
    }
    
    int getIndex(int idx) {
        if (idx >= arr.size()) return -1;
        // Apply current transformation to stored value
        return (arr[idx] * mul + add) % MOD;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */