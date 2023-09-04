class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int>st;
        int n=arr.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i] < 0 && st.top()> 0 && st.top() < abs(arr[i])){
                st.pop();
            }
            if(!st.empty() && arr[i] <0 && st.top() > 0 && st.top() == abs(arr[i])){
                st.pop();
                continue;
            }
            if(!st.empty() && arr[i] < 0 && st.top() >0 && st.top() > arr[i]){
                continue;
            }
            st.push(arr[i]);
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};