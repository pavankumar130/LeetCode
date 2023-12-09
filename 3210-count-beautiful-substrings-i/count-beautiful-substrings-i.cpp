class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        
        int count = 0;
        int n=s.length();

        for(int i=0; i<n; i++){
            unordered_map<int,int>mp;
            for(int j=i; j<n; j++){
               mp[s[j]]++;

               int vowels=0;
               int consonants = 0;
               for(auto it:mp){
                   if(it.first == 'a' || it.first == 'e' || it.first == 'i' || it.first == 'o' || it.first == 'u'){
                       vowels+=it.second;
                   }
                   else{
                      consonants+=it.second; 
                   }
               }
               if(consonants == vowels){
                   if( (consonants*vowels)%k == 0 ){
                       count++;
                   }
               }
            }
        }
        return count;
    }
};