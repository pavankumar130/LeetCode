class Solution {
    static bool cmp(int &a, int &b){
        return a > b;
    }
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();

        sort(happiness.begin(), happiness.end(), cmp);

        long long sum = 0;
        long long cnt = 0;

        for(int i = 0; i < n; i++){
            if(cnt == k || happiness[i] <= cnt){
                break;
            }

            sum += (happiness[i] - (cnt));
            cnt++;
        }
        return sum;
    }
};