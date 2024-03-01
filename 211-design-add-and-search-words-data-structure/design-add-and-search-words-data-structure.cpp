class Trie {
public:
    bool isend;
    vector<Trie*> arr;
    Trie(){
        isend = false;
        arr.resize(26, NULL);
    }
};

class WordDictionary {
    Trie* root;

public:
    WordDictionary() {
        root = new Trie();
    }

    void addWord(string word) {
        Trie* node = root;
        for (char c : word) {
            if (!node->arr[c - 'a']) {
                node->arr[c - 'a'] = new Trie();
            }
            node = node->arr[c - 'a'];
        }
        node->isend = true;
    }

    bool search(string word) {
        return searchHelper(word, root, 0);
    }

private:
    bool searchHelper(const string& word, Trie* node, int index) {
        if (index == word.size()) {
            return node->isend;
        }

        if (word[index] == '.') {
            for (Trie* child : node->arr) {
                if (child && searchHelper(word, child, index + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            if (!node->arr[word[index] - 'a']) {
                return false;
            }
            return searchHelper(word, node->arr[word[index] - 'a'], index + 1);
        }
    }
};