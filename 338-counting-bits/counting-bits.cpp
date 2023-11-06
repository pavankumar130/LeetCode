class Solution {
public:
int solve(int n){
    int count=0;
    while(n){
        if(n%2 != 0){
            count++;
        }
        n/=2;
    }
    return count;
}
    vector<int> countBits(int n) {
        vector<int>res;
        res.push_back(0);
        for(int i=1; i<=n;i++){
            res.push_back( (solve(i)) );
        }
        return res;
    }
};