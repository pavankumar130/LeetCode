class Solution {
    bool check(const string & curr, const string & temp){
        unordered_set<char>st;
        for(char ch:temp){
            if(st.count(ch) > 0){
                return false;
            }
            st.insert(ch);
            if(curr.find(ch) != string::npos){
                return false;
            }
        }
        return true;
    }
    void solve(vector<string>&arr, string temp, int ind, int&res){
        if(res < temp.size()){
            res = temp.size();
        }

        for(int i = ind; i < arr.size(); i++){
            if( check(temp,arr[i]) == false){
                continue;
            }
            solve(arr,temp + arr[i],i+1,res);
        }
    }
public:
    int maxLength(vector<string>& arr) {
        int res = 0;
        solve(arr,"",0,res);
        return res;
    }
};