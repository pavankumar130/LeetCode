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
    map<int, int>mp;
    TreeNode* solve(int pre_s, int pre_e, int post_s, vector<int>& preorder){
        if(pre_s > pre_e){
            return NULL;
        }
        if (pre_s == pre_e){
            return new TreeNode(preorder[pre_s]);
        }

        TreeNode * root = new TreeNode(preorder[pre_s]);
        int left_sub_root = preorder[pre_s + 1];
        int left_sub_size = mp[left_sub_root] - post_s + 1;

        root->left = solve(pre_s + 1, pre_s + left_sub_size, post_s, preorder);
        root->right = solve(pre_s + left_sub_size + 1, pre_e, post_s + left_sub_size, preorder);
        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        for(int i = 0; i < n; i++){
            mp[postorder[i]] = i;
        }

        return solve(0, n-1, 0, preorder);
    }
};