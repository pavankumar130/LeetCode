class Node{
    public:
    Node* children[26];
    bool flag = false;

    Node(){
        for(int i=0; i<26; i++){
            children[i]=NULL;
        }
    }
};

class Trie {
    Node* root;
public:
    Trie() {
       root = new Node(); 
    }
    
    void insert(string word) {
        Node* node = root;

        for(int i=0; i<word.length(); i++){
            if(node->children[word[i]-'a'] == NULL){
                node->children[word[i]-'a'] = new Node();
            }
            node = node->children[word[i]-'a'];
        }
        node->flag = true;
    }
    
    bool search(string word) {
        Node* node = root;

        for(int i=0; i<word.length(); i++){
            if(node->children[word[i]-'a'] == NULL){
                return false;
            }
            node = node->children[word[i]-'a'];
        }
        return node->flag;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;

        for(int i=0; i<prefix.length(); i++){
            if(node->children[prefix[i]-'a'] == NULL){
                return false;
            }
            node = node->children[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */