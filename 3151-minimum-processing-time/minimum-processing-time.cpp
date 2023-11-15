class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {

        int n=processorTime.size();

        sort(processorTime.begin(),processorTime.end());
        sort(tasks.begin(),tasks.end());

        int ind=n-1;

        int res=0;

        for(int i=1; i<=tasks.size(); i++){
           res=max(res, processorTime[ind]+tasks[i-1]);
           if(i%4 == 0){
               ind--;
           }
        }
        return res;
    }
};