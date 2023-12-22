class Solution {
public:
    int maxScore(string s) {
        
        int ones = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '1'){
                ones++;
            }
        }

        int maxi = 0;
        int zeroes = 0;
        for(int i=0; i<s.length()-1; i++){
            if(s[i] == '1'){
                ones--;
            }
            else{
                zeroes++;
            }

            maxi = max(maxi,zeroes+ones);
        }
        return maxi;
    }
};