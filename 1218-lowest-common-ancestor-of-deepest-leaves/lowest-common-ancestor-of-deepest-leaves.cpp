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
 #include<bits/stdc++.h>
class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*>q;
        vector<TreeNode*>last;
        q.push(root);
        parent[root] = NULL;

        while(q.size()){
            int n = q.size();
            last.clear();
            for(int i = 0; i < n; i++){
                TreeNode * node = q.front();
                q.pop();

                if(node->left){
                    parent[node->left] = node;
                    q.push(node->left);
                }

                if(node->right){
                    parent[node->right] = node;
                    q.push(node->right);
                }

                last.push_back(node);
            }
        }

        set<TreeNode*>deepest(last.begin(), last.end());

        while(deepest.size() > 1){
            set<TreeNode*>st;

            for(auto it: deepest){
                st.insert(parent[it]);
            }

            deepest = st;
        }

        return *deepest.begin();
    }
};