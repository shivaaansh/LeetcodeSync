struct Node {
    int sum, mini, maxi;
    bool isBST;
    Node(int s, int mn, int mx, bool b) {
        sum = s;
        mini = mn;
        maxi = mx;
        isBST = b;
    }
};

class Solution {
public:
    int ans = 0;

    Node* f(TreeNode* root) {
        if (!root)
            return new Node(0, INT_MAX, INT_MIN, true);

        auto L = f(root->left);
        auto R = f(root->right);

        if (L->isBST && R->isBST &&
            root->val > L->maxi && root->val < R->mini) {

            int currSum = root->val + L->sum + R->sum;
            ans = max(ans, currSum);

            return new Node(
                currSum,
                min(root->val, L->mini),
                max(root->val, R->maxi),
                true
            );
        }

        return new Node(
            0,
            INT_MIN,
            INT_MAX,
            false
        );
    }

    int maxSumBST(TreeNode* root) {
        f(root);
        return ans;
    }
};
