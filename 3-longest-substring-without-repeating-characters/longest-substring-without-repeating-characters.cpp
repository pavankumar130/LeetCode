class Solution {
public:
    int lengthOfLongestSubstring(string S) {
        unordered_set<char>st;
        int maxi=0;
        int left=0;
        for(int right=0;right<S.size();right++){
            while(st.count(S[right]) > 0){
                st.erase(S[left]);
                left++;
            }
            st.insert(S[right]);
            maxi=max(maxi, right-left+1);
        }
        return maxi;
    }
};