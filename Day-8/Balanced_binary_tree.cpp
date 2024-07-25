class Solution {
private:
    int height(TreeNode* root) {
        if (root == NULL)
            return 0;
        int l = height(root->left);
        int r = height(root->right);

        return 1 + max(l, r);
    }

public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;

        int l = height(root->left);
        int r = height(root->right);
        if (abs(l - r) > 1)
            return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};
