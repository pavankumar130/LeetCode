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
TreeNode* prev=NULL;
void solve(TreeNode* root, int &res){
    if(root == NULL){
        return;
    }
    solve(root->left,res);
    if(prev != NULL){
        res = min(res, abs(root->val - prev->val));
    }
    prev=root;
    solve(root->right,res);
}
    int getMinimumDifference(TreeNode* root) {
        int res=INT_MAX;
        solve(root,res);
        return res;
    }
};