class Solution {

   class Node{
       public:
       Node* children[2];
   };
   
   class Trie{
       Node* root;

       public:
       Trie(){
         root = new Node();
       }

       void put(int num){
          Node* node = root;

          for(int i=31; i>=0; i--){
              int bit = (num >> i) & 1;
              if(!node->children[bit]){
                  node->children[bit] = new Node();
              }
              node = node->children[bit];
          }
       }

       int getmaxi(int num){
          Node* node = root;
          int maxi = 0;
          for(int i=31; i>=0; i--){
              int bit = (num >> i) & 1;
              if(node->children[1-bit] != NULL){
                  maxi = maxi | (1<<i);
                  node = node->children[1-bit];
              }
              else{
                  node = node->children[bit];
              }
          }
          return maxi;
       }
   };
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(int i=0; i<nums.size(); i++){
            trie.put(nums[i]);
        }

        int maxi = 0;
        for(int i=0; i<nums.size(); i++){
            maxi = max(maxi ,trie.getmaxi(nums[i]));
        }
        return maxi;
    }
};