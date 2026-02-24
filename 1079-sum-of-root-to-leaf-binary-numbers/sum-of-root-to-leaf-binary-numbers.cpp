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
    long long sum = 0;
    void solve(TreeNode* root, vector<int>&bits){
        if(root->left == NULL && root->right == NULL){
            bits.push_back(root->val);
            reverse(bits.begin(), bits.end());
            int curr = 0;
            for(int i = 0; i < bits.size(); i++){
                curr += bits[i] * pow(2, i);
            }
            reverse(bits.begin(), bits.end());
            bits.pop_back();
            sum += curr;
        }

        bits.push_back(root->val);
        if(root->left){
            solve(root->left, bits);
        }
        if(root->right){
            solve(root->right, bits);
        }

        bits.pop_back();
    }
    int sumRootToLeaf(TreeNode* root) {
        vector<int>bits;
        solve(root, bits);
        return int(sum);
    }
};