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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;

        queue<pair<TreeNode*,bool>>q;
        q.push({root, false});

        while(q.size()){
            TreeNode* node = q.front().first;
            bool isleft = q.front().second;
            q.pop();

            if(isleft && !node->left && !node->right){
                sum += node->val;
            }

            if(node->left){
                q.push({node->left, true});
            }
            if(node->right){
                q.push({node->right, false});
            }
        }

        return sum;
    }
};