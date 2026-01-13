#include<bits/stdc++.h>

class Solution {
bool check(double y, vector<vector<int>>& squares, double totalarea){
    double part2 = 0;

    for(auto& it: squares){
        double yi = it[1];
        double side = it[2];

        if(yi > y){
           continue; 
        }
        else{
            double final_y = yi + it[2];
            if(final_y <= y){
                part2 += (side * side);
            }
            else{
                part2 += ((y - yi) * side);
            }
        }
    }

    return part2 < totalarea / 2;
}
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = 2e9;
        double high = 0;
        double totalarea = 0;

        for(auto& it: squares){
            double y = it[1];
            double side = it[2];

            totalarea += (side * side);

            low = min(low, y);
            high = max(high, y + side);
        }


        while(high - low >= 1e-6){
            double mid = (low + high) / 2;

            if(check(mid, squares, totalarea)){
                low = mid + 1e-6;
            }
            else{
                high = mid - 1e-6;
            }
        }

        return low;
    }
};