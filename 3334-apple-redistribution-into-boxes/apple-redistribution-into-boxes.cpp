class Solution {
    static bool cmp(int &a, int &b){
        return a > b;
    }
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = 0;

        for(int i = 0; i < apple.size(); i++){
            sum += apple[i];
        }

        sort(capacity.begin(), capacity.end(), cmp);

        int cnt = 0;

        for(int i = 0; i < capacity.size(); i++){
            if(sum == 0){
                break;
            }
            if(sum <= capacity[i]){
                cnt++;
                break;
            }
            sum -= capacity[i];
            cnt++;
        }

        return cnt;
    }
};