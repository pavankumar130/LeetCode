class Solution {
    public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
        int i=0; 
        int j=0;

        for(String s:word1){
            for(char c:s.toCharArray()){
               if (i == word2.length || word2[i].charAt(j) != c) {
                   return false;
               }
               j++;
               if(j == word2[i].length()){
                   i++;
                   j=0;
               }
            }
        }
        return i == word2.length;
    }
}