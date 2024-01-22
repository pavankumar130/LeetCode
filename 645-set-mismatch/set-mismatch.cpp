class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        set<int>st;
        vector<int>res;

        for(int i = 0; i < nums.size(); i++){
            if(st.find(nums[i]) != st.end()){
                res.push_back(nums[i]);
                continue;
            }
            st.insert(nums[i]);
        }

        for(int i = 1; i <= nums.size(); i++){
            if(st.find(i) == st.end()){
                res.push_back(i);
            }
        }
        return res;
    }
};