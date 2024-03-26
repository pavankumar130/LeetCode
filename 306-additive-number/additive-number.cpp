class Solution {
    bool solve(long long n1, long long n2, string str, bool found){
        if(str.size() == 0 && found){
            return true;
        }

        string n3 = to_string(n1 + n2);
        int ind = min(str.size(), n3.size());

        if(str.substr(0, ind) == n3){
            return solve(n2, stol(n3), str.substr(ind), true);
        }
      return false;
    }
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();

        for(int i = 1; i < n-1; i++){
            long long n1 = stol(num.substr(0, i));
            if(to_string(n1) != num.substr(0, i)){
                break;
            }
            for(int j = i+1; j < n; j++){
                long long n2 = stol(num.substr(i, j-i));
                if(to_string(n2) != num.substr(i, j-i)){
                    break;
                }

                bool found = solve(n1, n2, num.substr(j), false);
                if(found){
                    return true;
                }
            }
        }

        return false;
    }
};