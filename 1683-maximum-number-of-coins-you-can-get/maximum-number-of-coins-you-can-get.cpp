class Solution {
public:
    int maxCoins(vector<int>& piles) {
         sort(piles.begin(),piles.end());
         deque<int>dq;
         for(int i=0; i<piles.size(); i++){
             dq.push_back(piles[i]);
         }

         int ans=0;
         while(!dq.empty()){
             dq.pop_back(); // alice
             ans+=dq.back(); // us
             dq.pop_back();
             dq.pop_front();
         }
       return ans;
    }
};