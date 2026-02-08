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
    int Height(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        return 1 + max(Height(root->left), Height(root->right));
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }

        int leftH = Height(root->left);
        int rightH = Height(root->right);

        if(abs(leftH - rightH) > 1){
            return false;
        }

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        if(!left || !right){
            return false;
        }
        return true;
    }
};