class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        stack<pair<int,int>>st;
        stack<pair<int,int>>st1;
        vector<int>left(n);
        vector<int>right(n);
        int mode=1e9+7;
        int count=0;
        for(int i=0;i<n;i++){
           count=1;
           while(!st.empty() && st.top().first > arr[i]){
               count+=st.top().second;
               st.pop();
           } 
           st.push({arr[i],count});
           left[i]=count;
        }
        for(int i=n-1;i>=0;i--){
            count=1;
            while(!st1.empty() && st1.top().first >= arr[i]){
                count+=st1.top().second;
                st1.pop();
            }
            st1.push({arr[i],count});
            right[i]=count;
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum=(sum+((long long)arr[i]*left[i]*right[i])%mode)%mode;
        }
        return sum;
    }
};