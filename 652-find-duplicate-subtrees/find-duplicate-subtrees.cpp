class Solution {
public:
    
    unordered_map<string, int> mp;

    vector<TreeNode*> ans;

    string dfs(TreeNode* root) {
        if (root == NULL) return "#";

        string left = dfs(root->left);

        string right = dfs(root->right);

        string curr = to_string(root->val) + "," + left + "," + right;

        if (mp[curr] == 1) {
            ans.push_back(root);
        }

        mp[curr]++;

        return curr;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
