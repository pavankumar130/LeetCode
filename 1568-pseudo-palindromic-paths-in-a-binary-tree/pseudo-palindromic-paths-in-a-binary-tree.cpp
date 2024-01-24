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
    bool check(vector<int>&temp){
        int cnt = 0;
        for(int i = 1; i < 10; i++){
            if(temp[i]%2){
                cnt++;
            }
        }
        return cnt <= 1;
    }
    int solve(TreeNode* root, vector<int>&temp){
        if(root == NULL){
            return 0;
        }

        temp[root->val]++;

        if(!root ->left && !root->right){
            int cnt = check(temp);
            temp[root->val]--;
            return cnt;
        }

        int l = solve(root->left,temp);
        int r = solve(root->right,temp);
        temp[root->val]--;

        return l + r;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>temp(10,0);
        return solve(root,temp);
    }
};