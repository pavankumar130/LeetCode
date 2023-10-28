class Solution {
public:
unordered_map<string,unordered_map<string,double>> solve(vector<vector<string>>& equations, vector<double>& values){
    unordered_map<string,unordered_map<string,double>>gr;

    for(int i=0;i<equations.size();i++){
        string u=equations[i][0];
        string v=equations[i][1];
        double val=values[i];
        gr[u][v]=val;
        gr[v][u]=1.0/val;
    }
    return gr;
}

void dfs(string u, string v, unordered_map<string,unordered_map<string,double>>&gr,unordered_set<string>&st,double &a, double temp){
    if(st.find(u) != st.end()){
        return;
    }
    st.insert(u);
    if(u == v){
        a=temp;
        return;
    }

    for(auto it:gr[u]){
        dfs(it.first,v,gr,st,a,temp*it.second);
    }
}
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,unordered_map<string,double>> gr=solve(equations,values);

        vector<double>ans;
        for(int i=0;i<queries.size(); i++){
            string u=queries[i][0];
            string v=queries[i][1];
            if(gr.find(u) == gr.end() || gr.find(v) == gr.end()){
                ans.push_back(-1.0);
            }
            else{
                unordered_set<string>st;
                double a=-1,temp=1.0;
                dfs(u,v,gr,st,a,temp);
                ans.push_back(a);
            }
        }
        return ans;
    }
};