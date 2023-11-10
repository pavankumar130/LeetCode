class Solution {
public:
void solve(int n, set<int>&st){
    for(int i=2; i<=n; i++){
        while(n%i == 0){
            st.insert(i);
            n/=i;
        }
    }
}
    int distinctPrimeFactors(vector<int>& nums) {
        set<int>st;
        for(int i=0; i<nums.size();i++){
            solve(nums[i],st);
        }
      return st.size();
    }
};