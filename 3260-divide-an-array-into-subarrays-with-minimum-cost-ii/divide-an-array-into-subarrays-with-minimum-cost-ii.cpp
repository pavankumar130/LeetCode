class Solution {
public:
    class OrderSet{
        public:
        multiset<int> low;
        multiset<int> high;
        int dist;
        int k;
        long long windowsum;

        OrderSet(int dist, int k){
            windowsum = 0;
            this->dist = dist;
            this->k = k;
        }

        void rebalance(){
            while(high.size() > 0 && low.size() < k - 1){
                auto it = high.begin();
                low.insert(*it);
                windowsum += (*it);
                high.erase(it);
            }

            while(low.size() > k - 1){
                auto it = low.rbegin();
                high.insert(*it);
                windowsum -= (*it);
                low.erase(low.find(*it));
            }
        }

        void Delete(int x){
            if(low.find(x) != low.end()){
                low.erase(low.find(x));
                windowsum -= x;
            }
            else{
                high.erase(high.find(x));
            }

            rebalance();
        }

        void Insert(int x){
            if(high.size() > 0 && *(high.begin()) <= x){
                high.insert(x);
            }
            else{
                low.insert(x);
                windowsum += x;
            }
            rebalance();
        }
    };


    long long minimumCost(vector<int>& nums, int k, int dist) {
        long long res = 1e18;
        int n = nums.size();

        OrderSet s(dist, k);

        for(int i = 1; i < n; i++){
            s.Insert(nums[i]);

            if(i - dist - 1 > 0){
                s.Delete(nums[i - dist - 1]);
            }

            if(s.low.size() == k - 1){
                res = min(res, s.windowsum + nums[0]);
            }
        }

        return res;
    }
};