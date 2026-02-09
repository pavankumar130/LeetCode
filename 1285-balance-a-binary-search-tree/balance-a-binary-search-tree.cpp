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
    void Inorder(TreeNode* root, vector<int>&arr){
        if(root == NULL){
            return;
        }
        Inorder(root->left, arr);
        arr.push_back(root->val);
        Inorder(root->right, arr);
    }

    TreeNode* CreateBalanceBST(vector<int>&arr, int l, int r){
        if(l > r){
            return NULL;
        }

        int mid = (l + r) / 2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = CreateBalanceBST(arr, l, mid - 1);
        root->right = CreateBalanceBST(arr, mid + 1, r);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>arr;
        Inorder(root, arr);

        TreeNode* res = CreateBalanceBST(arr, 0, arr.size() - 1);
        return res;
    }
};