class Solution {
public:
    string sortVowels(string s) {
        vector<char>arr;

        for(int i=0; i<s.length(); i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||s[i] == 'u' ){
                arr.push_back(s[i]);
            }
            if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' ||s[i] == 'U' ){
                arr.push_back(s[i]);
            }
        }
        if(arr.size() < 2){
          return s;
        }
        sort(arr.begin(),arr.end());
        int ind =0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||s[i] == 'u' || 
                 s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' ||s[i] == 'U'  ){
                s[i]=arr[ind];
                ind++;
            }
        }
        return s;
    }
};