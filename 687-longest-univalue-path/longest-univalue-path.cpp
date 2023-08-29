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
int solve(TreeNode* root, int &ans){
    if(root == NULL){
        return 0;
    }
    int left=solve(root->left,ans);
    int right=solve(root->right,ans);

    int lmaxi=0,rmaxi=0;
    if(root->left && root->left->val == root->val){
        lmaxi=1+left;
    }
    if(root->right && root->right->val == root->val){
        rmaxi=1+right;
    }
    int temp=max(rmaxi,lmaxi);
    ans=max(ans, rmaxi+lmaxi);
    return temp;
}
    int longestUnivaluePath(TreeNode* root) {
        int ans=0;
        solve(root,ans);
        return ans;
    }
};