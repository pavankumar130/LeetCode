class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>>st;
        int n=path.length();
        
        int x = 0;
        int y = 0;
        st.insert({x,y});

        for(int i=0; i<n; i++){
            if(path[i] == 'N'){
               x = x-1;
               if(st.find({x,y}) != st.end()){
                   return true;
               }
               st.insert({x,y});
            }
            else if(path[i] == 'S'){
               x = x+1;
               if(st.find({x,y}) != st.end()){
                   return true;
               }
               st.insert({x,y});
            }
            else if(path[i] == 'E'){
               y = y+1;
               if(st.find({x,y}) != st.end()){
                   return true;
               }
               st.insert({x,y});
            }
            else{
               y = y-1;
               if(st.find({x,y}) != st.end()){
                   return true;
               }
               st.insert({x,y});
            }
        }
        return false;
    }
};