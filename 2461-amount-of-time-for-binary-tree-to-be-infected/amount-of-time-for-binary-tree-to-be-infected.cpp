// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
//     TreeNode* findInd(TreeNode* root, int start){
//         if(root == NULL){
//             return NULL;
//         }
//         queue<TreeNode*>q;
//         q.push(root);

//         while(!q.empty()){
//             TreeNode* node = q.front();
//             q.pop();
//             if(node->val == start){
//                 return node;
//             }
//             if(node->left){
//                 q.push(node->left);
//             }
//             if(node->right){
//                 q.push(node->right);
//             }
//         }
//         return NULL;
//     }
//     void solve(TreeNode* root, map<TreeNode*,TreeNode*>&mp){
//         if(root == NULL){
//             return;
//         }
//         queue<TreeNode*>q;
//         q.push(root);

//         while(!q.empty()){
//             TreeNode* node = q.front();
//             q.pop();

//             if(node->left){
//                 mp[node->left] = node;
//                 q.push(node->left);
//             }
//             if(node->right){
//                 mp[node->right] = node;
//                 q.push(node->right);
//             }
//         }
//     }
// public:
//     int amountOfTime(TreeNode* root, int start) {
//         if(root == NULL){
//             return 0;
//         }
//         if(root->left == NULL && root->right == NULL){
//             if(start == root->val){
//                 return 0;
//             }
//         }

//         TreeNode* s = findInd(root,start);
//         if(s == NULL){
//             return 0;
//         }
//         map<TreeNode*,TreeNode*>mp;
//         solve(root,mp);
//         int res = -1;
//         queue<TreeNode*>q;
//         q.push(s);
//         set<TreeNode*>st;
//         while(!q.empty()){
//             int n = q.size();
//             res++;
//             for(int i = 0; i < n; i++){
//                 TreeNode* node = q.front();
//                 q.pop();
//                 st.insert(node);
//                 if(st.find(mp[node]) == st.end()){
//                     q.push(mp[node]);
//                 }
//                 if(node->left != NULL && st.find(node->left) == st.end()){
//                     q.push(node->left);
//                 }
//                 if(node->right != NULL && st.find(node->right) == st.end()){
//                     q.push(node->right);
//                 }
//             }
//         }
//         return res;
//     }
// };
class Solution {
    TreeNode* findInd(TreeNode* root, int start) {
        if (root == nullptr) {
            return nullptr;
        }
        queue<TreeNode*> q({root});

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->val == start) {
                return node;
            }
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
        return nullptr;
    }

    void solve(TreeNode* root, map<TreeNode*, TreeNode*>& mp) {
        if (root == nullptr) {
            return;
        }
        queue<TreeNode*> q({root});

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left) {
                mp[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                mp[node->right] = node;
                q.push(node->right);
            }
        }
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        if (root == nullptr) {
            return 0; // Handle empty tree
        }
        if (root->left == nullptr && root->right == nullptr) {
            if (start == root->val) {
                return 0;
            }
        }

        TreeNode* s = findInd(root, start);
        if (s == nullptr) {
            return 0; // Node not found in the tree
        }
        map<TreeNode*, TreeNode*> mp;
        solve(root, mp);
        int res = -1;
        queue<TreeNode*> q({s});
        set<TreeNode*> st;
        while (!q.empty()) {
            int n = q.size();
            res++;
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                st.insert(node);
                if (mp[node] && st.find(mp[node]) == st.end()) {
                    q.push(mp[node]);
                }
                if (node->left ){
                 if(st.find(node->left) == st.end()) {
                    q.push(node->left);
                 }
                }
                if (node->right ){
                  if(st.find(node->right) == st.end()) {
                    q.push(node->right);
                  }
                }
            }
        }
        return res;
    }
};