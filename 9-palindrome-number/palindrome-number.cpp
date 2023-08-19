class Solution {
public:
    bool isPalindrome(int x) {
        vector<int>v;
        if(x<0){
            return false;
        }
        while(x){
            v.push_back(x%10);
            x=x/10;
        }
        int low=0;
        int high=v.size()-1;
        while(low<high){
            if(v[low] != v[high]){
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
};