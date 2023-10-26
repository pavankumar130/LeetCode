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
void solve(TreeNode* root, vector<int>&arr, int sum){
    if(root->left == NULL && root->right == NULL){
        int num=sum*10+root->val;
        arr.push_back(num);
        return;
    }
    int num=sum*10+root->val;
    if(root->left){
        solve(root->left,arr,num);
    }
    if(root->right){
        solve(root->right,arr,num);
    }
}
    int sumNumbers(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        if(root->left == NULL && root->right == NULL){
            return root->val;
        }
        vector<int>arr;
        solve(root,arr,0);
        int sum=0;
        for(auto it:arr){
            sum+=it;
        }
        return sum;
    }
};