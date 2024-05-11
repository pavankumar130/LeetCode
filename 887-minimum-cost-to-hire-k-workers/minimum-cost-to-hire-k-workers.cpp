class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();

        double mini = DBL_MAX;
        double qualitytillnow = 0;

        vector<pair<double,int>>wagequalityratio;
        for(int i = 0; i < n; i++){
            wagequalityratio.push_back({(wage[i]*1.0/quality[i]), quality[i]});
        }

        sort(wagequalityratio.begin(), wagequalityratio.end());

        priority_queue<int>highqualityworker;

        for(int i = 0; i < n; i++){
            double ratio = wagequalityratio[i].first;
            int qua = wagequalityratio[i].second;

            qualitytillnow += qua;
            highqualityworker.push(qua);

            if(highqualityworker.size() > k){
                qualitytillnow -= highqualityworker.top();
                highqualityworker.pop();
            }
            if(highqualityworker.size() == k){
                mini = min(mini, qualitytillnow*ratio);
            }
        }

        return mini;
    }
};