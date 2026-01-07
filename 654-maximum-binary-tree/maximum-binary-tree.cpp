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
    TreeNode* f(int s, int e, vector<int> nums) {
        if(s > e) return NULL;
        int maxi = -1, maxI = -1;
        for(int i = s; i <= e; i++) {
            if(nums[i] > maxi) {
                maxi = nums[i];
                maxI = i;
            }
        }
        TreeNode* leftAns = f(s, maxI-1, nums);
        TreeNode* rightAns = f(maxI+1, e, nums);
        TreeNode* root = new TreeNode(maxi);
        root->left = leftAns;
        root->right = rightAns;
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return f(0, nums.size()-1, nums);
    }
};