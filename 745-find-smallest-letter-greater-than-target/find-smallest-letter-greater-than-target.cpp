class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        sort(letters.begin(), letters.end());
        int n = letters.size();
        int ind = -1;
        int low = 0, high = n - 1;

        while(low <= high){
            int mid = (low + high) / 2;

            if(letters[mid] - 'a' > target - 'a'){
                ind = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        if(ind == -1){
            return letters[0];
        }

        return letters[ind];
    }
};