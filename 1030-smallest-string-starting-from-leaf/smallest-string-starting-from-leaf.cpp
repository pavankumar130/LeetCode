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
    string ans = "|";
    void solve(TreeNode* root, string temp){
        if(root == NULL){
            return;
        }

        temp = string(1, root->val + 'a') + temp;
        if(root->left == NULL && root->right == NULL){
            ans = min(ans, temp);
        }
        solve(root->left, temp);
        solve(root->right, temp);
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        solve(root, {});
        return ans;
    }
};