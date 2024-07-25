class Solution {
public:
    int helper(TreeNode* root, int& maxD) {
        if (root == NULL)
            return 0;

        int l = helper(root->left, maxD);
        int r = helper(root->right, maxD);
        int h = max(l, r) + 1;
        maxD = max(maxD, l + r);

        return h;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxD = 0;
        helper(root, maxD);
        return maxD;
    }
};
