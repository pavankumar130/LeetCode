class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>>q;

        for(int i = 0; i < tickets.size(); i++){
            q.push({tickets[i], i});
        }

        int res = 0;

        while(q.size()){
            int num = q.front().first;
            int pos = q.front().second;
            q.pop();
            res = res + 1;
            num = num - 1;
            if(pos == k && !num ){
                return res;
            }
            if(num){
                q.push({num, pos});
            }
        }

        return res;
    }
};