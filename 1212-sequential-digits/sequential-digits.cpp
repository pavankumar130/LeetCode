class Solution {
    void solve(int digit, int low, int high, vector<int>&res, int num){
        if(num >= low && num <= high){
            res.push_back(num);
        }

        cout<<num<<" ";
        num = (num*10 + digit);
        if(num <= high && digit <= 9){
            solve(digit+1, low, high, res, num);
        }
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>res;

        for(int i = 1; i <= 9; i++){
            solve(i,low,high,res,0);
        }
        sort(res.begin(),res.end());
        return res;
    }
};