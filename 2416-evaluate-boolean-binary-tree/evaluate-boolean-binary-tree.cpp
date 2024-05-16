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
    bool evaluateTree(TreeNode* root) {
        if(root->left == NULL && root->right == NULL){
            return root->val;
        }

        if(root->left && root->right){
            bool left = evaluateTree(root->left);
            bool right = evaluateTree(root->right);

            if(root->val == 2){
                return (left | right);
            }
            else{
                return (left & right);
            }
        }

        else if(root->left){
            return evaluateTree(root->left);
        }
        else{
            return evaluateTree(root->right);
        }
    }
};