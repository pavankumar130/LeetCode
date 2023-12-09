class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        
        int count = 0;
        int n=s.length();

        for(int i=0; i<n; i++){
            int vowels=0;
            int consonants = 0;
            for(int j=i; j<n; j++){
                if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u'){
                    vowels++;
                }
                else{
                    consonants++; 
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