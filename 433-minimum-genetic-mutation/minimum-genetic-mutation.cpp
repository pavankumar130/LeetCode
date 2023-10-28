class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        char choices[]={'A','C','G','T'};
        unordered_set<string>st(bank.begin(),bank.end());
        if(st.find(endGene) == st.end()){
            return -1;
        }

        queue<string>q;
        q.push(startGene);
        int res=0;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                string curr=q.front();
                q.pop();
                if(curr == endGene){
                    return res;
                }
                for(int j=0;j<8;j++){
                   char c=curr[j];
                   for(int k=0;k<4; k++){
                       curr[j]=choices[k];
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
        return -1;
    }
};