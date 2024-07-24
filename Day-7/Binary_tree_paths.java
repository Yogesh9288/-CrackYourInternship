class Solution {
private:
    void helper(TreeNode* root, vector<string>& paths, string s) {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL) {
            s += to_string(root->val);
            paths.push_back(s);
            return;
        }
        s += to_string(root->val);
        helper(root->left, paths, s + "->");
        helper(root->right, paths, s + "->");
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        string s;
        helper(root, paths, s);
        return paths;
    }
};
