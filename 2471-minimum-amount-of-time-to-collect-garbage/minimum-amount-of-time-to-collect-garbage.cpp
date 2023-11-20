class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        
        int res=0;

        int lastM=0;
        int lastP=0;
        int lastG=0;

        int countM=0;
        int countP=0;
        int countG=0;

        vector<int>prefix(garbage.size(),0);
        for(int i=1; i<garbage.size(); i++){
            prefix[i]=prefix[i-1]+travel[i-1];
        }

        for(int i=0; i<garbage.size(); i++){

            string s=garbage[i];

            for(auto it:s){
                if(it == 'M'){
                    countM++;
                    lastM=i;
                }
                if(it == 'P'){
                    countP++;
                    lastP=i;
                }
                if(it == 'G'){
                    countG++;
                    lastG=i;
                }
            }
        }

        res+=(prefix[lastM]+countM);
        res+=(prefix[lastP]+countP);
        res+=(prefix[lastG]+countG);

        return res;
    }
};