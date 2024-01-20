class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        stack<pair<int,int>>st;
        vector<int>left(n);
        vector<int>right(n);
        int mod = 1e9+7;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            cnt = 1;
            while(!st.empty() && st.top().first > arr[i]){
                cnt += st.top().second;
                st.pop();
            }
            st.push({arr[i],cnt});
            left[i] = cnt;
        }

        while(!st.empty()){
            st.pop();
        }

        for(int i = n-1; i >= 0; i--){
            cnt = 1;
            while(!st.empty() && st.top().first >= arr[i]){
                cnt += st.top().second;
                st.pop();
            }
            st.push({arr[i],cnt});
            right[i] = cnt;
        }

        long long sum = 0;

        for(int i = 0; i < n; i++){
            sum = (sum + (long long)arr[i]*left[i]*right[i]%mod)%mod;
        }
        return sum;
    }
};