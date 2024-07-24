class Solution {
    private boolean helper(TreeNode s, TreeNode t) {
        if (s == null && t == null)
            return true;
        if (s == null || t == null)
            return false;
        if (s.val != t.val)
            return false;

        return helper(s.right, t.left) && helper(s.left, t.right);
    }

    public boolean isSymmetric(TreeNode root) {
        return helper(root.left, root.right);
    }
}
