class Solution {
public:
    string makeLargestSpecial(string s) {
        int cnt = 0;
        int start = 0;

        int n = s.size();
        vector<string>blocks;

        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                cnt++;
            }
            else{
                cnt--;
            }

            if(cnt == 0){
                string sub = s.substr(start + 1, i - start - 1);
                string block = "1" + makeLargestSpecial(sub) + "0";
                start = i + 1;
                blocks.push_back(block);
            }
        }

        sort(blocks.rbegin(), blocks.rend());
        string ans = "";
        for(auto it: blocks){
            ans += it;
        }

        return ans;
    }
};