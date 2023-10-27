/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
Node* solve(Node* node, unordered_map<int,Node*>&mp){
    Node* new_node = new Node(node->val);
    mp[node->val]=new_node;
    for(auto it:node->neighbors){
        if(mp.find(it->val) != mp.end()){
           new_node->neighbors.push_back(mp[it->val]);
        }
        else{
            Node* cn =solve(it,mp);
            new_node->neighbors.push_back(cn);
        }
    }
    return new_node;
}
    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return NULL;
        }
        unordered_map<int,Node*>mp;
        return solve(node,mp);
    }
};