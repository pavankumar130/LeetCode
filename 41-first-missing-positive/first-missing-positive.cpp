class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int>st;

        for(auto it: nums){
            if(it <= 0){
                continue;
            }
            st.insert(it);
        }

        int res = 1;

        for(auto it:st){
           if(it != res){
            return res;
           }
           res++;
        }

        return res;
    }
};