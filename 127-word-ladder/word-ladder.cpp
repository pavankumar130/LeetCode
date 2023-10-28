class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        if(st.find(endWord) == st.end()){
            return 0;
        }

        queue<string>q;
        q.push(beginWord);
        int res=1;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                string curr=q.front();
                q.pop();
                if(curr == endWord){
                    return res;
                }
                for(int j=0;j<curr.length();j++){
                   char c=curr[j];
                   for(char ch='a';ch<='z'; ch++){
                       curr[j]=ch;
                       if(st.find(curr) != st.end()){
                           st.erase(curr);
                           q.push(curr);
                       }
                   }
                   curr[j]=c;
                }
            }
            res++;
        }
        return 0;
    }
};