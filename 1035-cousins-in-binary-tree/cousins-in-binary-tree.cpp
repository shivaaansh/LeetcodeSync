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
    unordered_map<int,int> level;
    unordered_map<int, int> par;

    void dfs(TreeNode* root, int l) {
        if(root == NULL) return;
        level[root->val] = l;
        if(root->left) {
            par[root->left->val] = root->val;
            dfs(root->left, l+1);
        }
        if(root->right) {
            par[root->right->val] = root->val;
            dfs(root->right, l+1);
        }
    }
    bool isCousins(TreeNode* root, int x, int y) {
        int l = 0;
        level[root->val] = l;
        par[root->val] = -1;
        dfs(root, l);
        if(par[x] != par[y] && level[x] == level[y]) {
            return true;
        }
        return false;
    }
};