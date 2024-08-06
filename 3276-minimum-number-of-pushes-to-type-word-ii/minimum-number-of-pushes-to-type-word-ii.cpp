class Solution {
    void solve(vector<int>&freq, vector<int>&num){
        
        priority_queue<pair<int,int>>pq;
        
        for(int i = 0; i < 26; i++){
            if(freq[i]){
                pq.push({freq[i], i});
            }
        }
        
        int cnt = 1;
        int temp = 1;
        
        while(!pq.empty()){
            int ind = pq.top().second;
            pq.pop();
            num[ind] = cnt;
            temp++;
            if(temp > 8){
                temp = 1;
                cnt++;
            }
        }
        
    }
public:
    int minimumPushes(string word) {
        vector<int>number(26,0);
        vector<int>freq(26,0);
        
        for(int i = 0; i < word.size(); i++){
            freq[word[i]-'a']++;
        }
        
        solve(freq,number);
        int res = 0;
        
        for(int i = 0; i < 26; i++){
            if(freq[i]){
                cout<<char(i+'a')<<" "<<freq[i] <<" "<<number[i]<<endl;
            }
            res += (number[i]*freq[i]);
        }
        return res;
    }
};