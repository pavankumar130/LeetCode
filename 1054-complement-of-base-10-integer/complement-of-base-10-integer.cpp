class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0){
            return 1;
        }

        vector<int>bits;
        
        while(n){
            bits.push_back(n % 2);
            n /= 2;
        }

        for(int i = 0; i < bits.size(); i++){
            if(bits[i]){
                bits[i] = 0;
            }
            else{
                bits[i] = 1;
            }
        }
        
        int res = 0;
        for(int i = 0; i < bits.size(); i++){
            cout<<i<<" "<<bits[i]<<endl;
            res += (bits[i] * pow(2, i));
        }

        return res;
    }
};