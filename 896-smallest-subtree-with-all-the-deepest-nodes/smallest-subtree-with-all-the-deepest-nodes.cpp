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
    TreeNode * res = NULL;
    int max_depth = -1;
    int solve(TreeNode* root, int depth){
        if(root == NULL){
            return depth;
        }

        int left_max = solve(root->left, depth + 1);
        int right_max = solve(root->right, depth + 1);

        if(left_max == right_max){
            if(max_depth <= left_max){
                res = root;
                max_depth = left_max;
            }
        }

        return max(left_max, right_max);
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        solve(root, 0);
        return res;
    }
};