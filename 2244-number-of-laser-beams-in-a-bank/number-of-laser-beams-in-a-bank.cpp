class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int>temp;

        for(int i=0; i<bank.size(); i++){
            int cnt = 0;
            for(int j = 0; j < bank[i].size(); j++){
                if(bank[i][j] == '1'){
                    cnt++;
                }
            }

            if(cnt){
                temp.push_back(cnt);
            }
        }

        int res = 0;
        if(temp.size() <= 1){
            return res;
        }

        for(int i = 1; i < temp.size(); i++){
            int num = temp[i-1]*temp[i];
            res += num;
        }
        return res;
    }
};