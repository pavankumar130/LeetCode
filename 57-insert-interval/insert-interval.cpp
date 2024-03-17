class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());

        vector<vector<int>>res;
        int n=intervals.size();
         
        int i=0;
        while(i<n){
            vector<int>temp=intervals[i];

            int j=i+1;
            while(j<n){
                if(intervals[j][0] <= temp[1]){
                    temp[1]=max(temp[1],intervals[j][1]);
                    j++;
                }
                else{
                    break;
                }
            }
            res.push_back(temp);
            i=j;
        }
        return res;
    }
};