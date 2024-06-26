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
    vector<int>arr;
    void inorder(TreeNode* root){
        if(root == NULL){
            return;
        }

        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }

    TreeNode* solve(int start, int end){
        if(start > end){
            return NULL;
        }

        int mid = (start + end)/2;

        TreeNode* root = new TreeNode(arr[mid]);
        root -> left = solve(start, mid - 1);
        root -> right = solve(mid + 1, end);

        return root;
    }    

public:
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);

        int n = arr.size();
        return solve(0, n-1);
    }
};