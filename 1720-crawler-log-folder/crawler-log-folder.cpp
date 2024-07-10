class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt = 0;

        for(int i = 0; i < logs.size(); i++){
            if(cnt != 0 && logs[i] == "../"){
                cnt--;
            }
            else if(logs[i] == "./" || cnt == 0 && logs[i] == "../"){
                cout<<cnt<<" ";
                continue;
            }
            else{
                cnt++;
            }
            cout<<cnt<<" ";
        }

        return cnt;
    }
};