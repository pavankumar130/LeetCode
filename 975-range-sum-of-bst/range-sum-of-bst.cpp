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
    void solve(vector<int>&arr, TreeNode* root){
        if(root == NULL){
            return;
        }
        solve(arr,root->left);
        arr.push_back(root->val);
        solve(arr,root->right);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int>arr;
        solve(arr,root);

        int res = 0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] >= low && arr[i] <= high){
                res +=arr[i];
            }
        }
        return res;
    }
};