class Solution {
    int solve(string &str, int &i){
        int revision = 0;

        while(i < str.size() && str[i] != '.'){
            revision = revision * 10 + (str[i] - '0');
            i++;
        }
        i++;

        return revision;
    }
public:
    int compareVersion(string version1, string version2) {
        int i = 0;
        int j = 0;

        while(i < version1.size() || j < version2.size()){
            int revision1 = solve(version1, i);
            int revision2 = solve(version2, j);

            if(revision1 > revision2){
                return 1;
            }
            else if(revision1 < revision2){
                return -1;
            }
        }

        return 0;
    }
};