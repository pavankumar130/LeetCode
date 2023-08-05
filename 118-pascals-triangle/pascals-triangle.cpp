class Solution {
public:
vector<int> solve(int n){
    vector<int>v;
    v.push_back(1);
    int ans=1;
    for(int i=1;i<n;i++){
        ans=ans*(n-i)/i;
        v.push_back(ans);
    }
    return  v;
}
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(solve(i));
        }
        return ans;
    }
};