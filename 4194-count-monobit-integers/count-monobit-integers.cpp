class Solution {
    bool monobit(int n){
        set<int>st;

        while(n){
            st.insert(n % 2);
            n = n / 2;
        }

        for(auto it : st){
            cout<<it<<" ";
        }
        cout<<endl;
        return st.size() == 1;
    }
public:
    int countMonobit(int n) {
        int cnt = 1;

        for(int i = 1; i <= n; i++){
            if(monobit(i)){
                cnt++;
            }
        }

        return cnt;
    }
};