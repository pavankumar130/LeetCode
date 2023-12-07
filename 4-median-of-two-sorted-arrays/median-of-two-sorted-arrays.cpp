class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        vector<int>res;

            int n=a.size();
            int m=b.size();

            int i=0,j=0;
            while(i<n && j<m){
                if(a[i] < b[j]){
                    res.push_back(a[i]);
                    i++;
                }
                else{
                    res.push_back(b[j]);
                    j++;
                }
            }

            while(i<n){
                res.push_back(a[i]);
                i++;
            }
            while(j<m){
                res.push_back(b[j]);
                j++;
            }
        int size = res.size();
        int mid = size/2;
        if(size%2 == 0){
            return (res[mid]+res[mid-1])/2.0;
        }
        return res[mid];
    }
};