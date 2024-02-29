/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        int level = 0;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            vector<int>temp;
            for(int i = 0; i < n; i++){
                TreeNode* node = q.front();
                q.pop();
                if(level%2 != 0){
                    if(node->val %2 != 0 || temp.size() && temp.back() <= node->val){
                        return false;
                    }
                    temp.push_back(node->val);
                   
                }
                else{
                    if(node->val %2 == 0 || temp.size() && temp.back() >= node->val){
                        return false;
                    }
                    temp.push_back(node->val);
                }

                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            level++;
        }

        return true;
    }
};