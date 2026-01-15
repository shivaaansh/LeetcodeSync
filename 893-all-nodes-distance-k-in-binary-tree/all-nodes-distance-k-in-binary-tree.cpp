/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void getPar(TreeNode* root, TreeNode* p, unordered_map<TreeNode*, TreeNode*> &par) {
        if(root == NULL) return;
        par[root] = p;
        getPar(root->left, root, par);
        getPar(root->right, root, par);
    }
    void getK(TreeNode* root, int k, unordered_map<TreeNode*, TreeNode*> &par, unordered_map<TreeNode*, int> &vis, vector<int> &res) {
        if(root == NULL || vis[root]) return;
        vis[root] = true;
        if(k == 0) {
            res.push_back(root->val);
            return;
        }
        getK(root->left, k-1, par, vis, res);
        getK(root->right, k-1, par, vis, res);
        getK(par[root], k-1, par, vis, res);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> par;
        unordered_map<TreeNode*, int> vis;
        vector<int> res;
        getPar(root, NULL, par);
        getK(target, k, par, vis, res);
        return res;
    }
};