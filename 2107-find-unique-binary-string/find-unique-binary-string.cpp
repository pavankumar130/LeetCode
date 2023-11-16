class Solution {
public:
void solve(string &curr, string& res, bool &found, int &n, unordered_set<string>&st){
    if(found){
        return;
    }
    if(curr.size() == n){
        if(st.find(curr) == st.end()){
            res=curr;
            found=true;
        }
        return;
    }

    curr+='0';
    solve(curr,res,found,n,st);
    curr.pop_back();
    curr+='1';
    solve(curr,res,found,n,st);
    curr.pop_back();
}
    string findDifferentBinaryString(vector<string>& nums) {
        
        string res="";
        string curr="";
        bool found=false;
        unordered_set<string>st(nums.begin(),nums.end());
        int n=nums[0].size();
        solve(curr,res,found,n,st);
        return res;
    }
};