class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            // int s=intervals[i][0];
            // int e=intervals[i][1];
            // if(!ans.empty() && e<=ans.back()[1]){
            //     continue;
            // }
            // for(int j=i+1;j<n;j++){
            //     if(intervals[j][0] <= e){
            //         e=max(e,intervals[j][1]);
            //     }
            //     else{
            //         break;
            //     }
            // }
            // ans.push_back({s,e});
            if(ans.empty() || intervals[i][0] >ans.back()[1]){
                ans.push_back(intervals[i]);
            }
            else{
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }
        }
        return ans;
    }
};