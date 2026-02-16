class Solution {
public:
    int reverseBits(int n) {
        vector<int>bits;

        int temp = n;

        while(temp){
            bits.push_back(temp % 2);
            temp /= 2;
        }

        while(bits.size() <= 31){
            bits.push_back(0);
        }

        reverse(bits.begin(), bits.end());
        int res = 0;
        for(int i = 0; i < bits.size(); i++){
            res += (bits[i] * pow(2, i));
        }

        return res;
    }
};