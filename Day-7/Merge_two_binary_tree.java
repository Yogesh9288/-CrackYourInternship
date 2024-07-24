class Solution {
    private TreeNode helper(TreeNode s, TreeNode t) {
        if (s == null && t == null)
            return null;
        if (s == null)
            return t;
        if (t == null)
            return s;
        TreeNode temp = new TreeNode(s.val + t.val);
        temp.left = helper(s.left, t.left);
        temp.right = helper(s.right, t.right);

        return temp;
    }

    public TreeNode mergeTrees(TreeNode root1, TreeNode root2) {
        return helper(root1, root2);
    }
}
