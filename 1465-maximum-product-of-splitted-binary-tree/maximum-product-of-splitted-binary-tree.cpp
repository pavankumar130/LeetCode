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
    long long int FindTotalSum(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        long long int left = FindTotalSum(root->left);
        long long int right = FindTotalSum(root->right);
        long long int sum = (root->val + left + right);

        return sum;
    }

    long long int solve(TreeNode* root, long long int& maxproduct, long long int& totalsum){
        if(root == NULL){
            return 0;
        }

        long long int left = solve(root->left, maxproduct, totalsum);
        long long int right = solve(root->right, maxproduct, totalsum);

        long long int subtreesum = (root->val + left + right);
        long long int currproduct = (subtreesum * (totalsum - subtreesum));

        maxproduct = max(maxproduct, currproduct);

        return subtreesum;
    }
public:
    int maxProduct(TreeNode* root) {

        long long int totalsum = FindTotalSum(root);
        long long int maxproduct = 1;
        long long int mod = 1e9 + 7;
        solve(root, maxproduct, totalsum);
        return (maxproduct % mod);
    }
};