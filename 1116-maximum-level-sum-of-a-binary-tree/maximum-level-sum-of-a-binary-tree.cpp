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
    int maxLevelSum(TreeNode* root) {
        int res = 0;
        int max_sum = INT_MIN;

        queue<TreeNode*>q;
        q.push(root);
        int level = 0;
        while(q.size()){
            int n = q.size();
            int sum = 0;
            level++;
            for(int i = 0; i < n; i++){
                TreeNode * node = q.front();
                q.pop();
                sum += node -> val;

                if(node -> left){
                    q.push(node->left);
                }
                if(node -> right){
                    q.push(node->right);
                }
            }

            if(sum > max_sum){
                res = level;
                max_sum = sum;
            }
        }

        return res;
    }
};