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
    int res = 0;
    void solve(TreeNode* root, int mini, int maxi){
        if(root == NULL){
            return;
        }
        res = max(res, max(abs(mini - root->val), abs(maxi - root->val)));
        mini = min(mini, root->val);
        maxi = max(maxi, root->val);

        solve(root->left,mini,maxi);
        solve(root->right,mini,maxi);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int mini = root->val;
        int maxi = root->val;
        solve(root,mini,maxi);
        return res;
    }
};