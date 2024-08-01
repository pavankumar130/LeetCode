class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n = details.size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            string s = details[i].substr(11, 2);
            int num = stoi(s);
            if(num > 60){
                cnt++;
            }
        }

        return cnt;
    }
};