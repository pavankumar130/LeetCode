class Solution {
    int NumSetBits(int num){
        int cnt = 0;

        while(num){
            if(num % 2){
                cnt++;
            }

            num /= 2;
        }

        return cnt;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>>vec;

        for(int i = 0; i < arr.size(); i++){
            int num_set_bits = NumSetBits(arr[i]);
            vec.push_back({num_set_bits, arr[i]});
        }

        sort(vec.begin(), vec.end());

        vector<int>res;
        for(int i = 0; i < vec.size(); i++){
            res.push_back(vec[i].second);
        }

        return res;
    }
};