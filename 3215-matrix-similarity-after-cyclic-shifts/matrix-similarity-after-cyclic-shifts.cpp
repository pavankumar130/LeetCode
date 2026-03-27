class Solution {
    vector<int> leftshift(vector<int>arr, int k){
        reverse(arr.begin(), arr.begin() + k);
        reverse(arr.begin() + k, arr.end());
        reverse(arr.begin(), arr.end());
        return arr;
    }
    vector<int> rightshift(vector<int>arr, int k){
        reverse(arr.begin(), arr.end() - k);
        reverse(arr.end() - k, arr.end());
        reverse(arr.begin(), arr.end());
        return arr;
    }
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        k = (k % n);
        vector<vector<int>>transform(m, vector<int>(n));

        for(int i = 0; i < m; i++){
            if(i % 2){
               transform[i] =  rightshift(mat[i], k);
            }
            else{
                transform[i] =  leftshift(mat[i], k);
            }
        }

        return (mat == transform);
    }
};