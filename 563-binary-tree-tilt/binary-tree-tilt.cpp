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
    int ans = 0;
    int help(TreeNode* root) {
        if(root == NULL) return 0;
        int sum = root->val;
        int left = help(root->left);
        int right = help(root->right);
        ans += abs(left - right);
        sum += left + right;
        return sum ;
    } 
    int findTilt(TreeNode* root) {
        int sum = help(root);
        return ans;
    }
};