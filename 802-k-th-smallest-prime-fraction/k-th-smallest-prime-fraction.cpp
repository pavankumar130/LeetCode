class Solution {
    static bool cmp(pair<double,vector<int>>&a, pair<double,vector<int>>&b){
        return a.first < b.first;
    }
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        vector<pair<double,vector<int>>>temp;

        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                double val = (double)arr[i]/arr[j];
                temp.push_back({val, {arr[i], arr[j]}});
            }
        }

        sort(temp.begin(), temp.end(), cmp);
        vector<int>res = temp[k-1].second;
        return res;
    }
};