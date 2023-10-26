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
TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int prestart, int preend, int instart, int inend,unordered_map<int,int>&mp){
    if(prestart > preend || instart > inend){
        return NULL;
    }
    TreeNode* root = new TreeNode(preorder[prestart]);
    int ind=mp[preorder[prestart]];
    int rem=ind-instart;
    root->left=solve(preorder,inorder,prestart+1, prestart+rem, instart, ind-1,mp);
    root->right=solve(preorder,inorder,prestart+rem+1, preend, ind+1, inend,mp);
    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return solve(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1,mp);
    }
};