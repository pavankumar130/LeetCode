class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int res = INT_MIN;
        for(int l=0; l<m; l++){
            vector<int>temp(n,0);
            for(int r=l; r<m; r++){
                for(int k =0; k<n; k++){
                    temp[k]+=matrix[k][r];
                }

                set<int>st={0};
                int curr_sum =0;
                for(int sum: temp){
                    curr_sum += sum;
                    auto it = st.lower_bound(curr_sum - k);
                    if(it != st.end()){
                        res = max(res, curr_sum -*(it));
                    }
                    st.insert(curr_sum);
                }
            }
        }
        return res;
    }
};