class Solution {
    char turnleft(char c){
        if(c == '0'){
            return '9';
        }
        return c-1;
    }

    char turnright(char c){
        if(c == '9'){
            return '0';
        }
        return c+1;
    }

    vector<string> nextoptions(string s){
        vector<string>ans;

        for(int i = 0; i < 4; i++){
            string copy = s;
            copy[i] = turnright(s[i]);
            ans.push_back(copy);
            copy[i] = turnleft(s[i]);
            ans.push_back(copy);
        }
        return ans;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string>q;
        unordered_map<string,bool>vis;

        unordered_set<string>dead(deadends.begin(), deadends.end());

        q.push("0000");
        vis["0000"] = true;

        int level = 0;

        while(!q.empty()){
            int size = q.size();

            while(size--){
                string s = q.front();
                q.pop();

                if(s == target){
                    return level;
                }
                if(dead.find(s) != dead.end()){
                    continue;
                }

                for(string options: nextoptions(s)){
                    if(!vis[options]){
                        q.push(options);
                        vis[options] = true;
                    }
                }
            }

            level++;
        }

        return -1;
    }
};