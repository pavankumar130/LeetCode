class FoodRatings {
    unordered_map<string,int>foodRatingmap;
    unordered_map<string,string>foodcuisinemap;
    unordered_map<string,set<pair<int,string>>>cusinefoodmap;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        
        for(int i=0; i<foods.size(); i++){
            foodRatingmap[foods[i]]=ratings[i];
            foodcuisinemap[foods[i]]=cuisines[i];

            cusinefoodmap[cuisines[i]].insert({-ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto cuisineName = foodcuisinemap[food];

        auto oldElementIterator = cusinefoodmap[cuisineName].find({-foodRatingmap[food],food});
        cusinefoodmap[cuisineName].erase(oldElementIterator);
        foodRatingmap[food]=newRating;
        cusinefoodmap[cuisineName].insert({-newRating,food});
    }
    
    string highestRated(string cuisine) {
        auto highest = *cusinefoodmap[cuisine].begin();

        return highest.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */