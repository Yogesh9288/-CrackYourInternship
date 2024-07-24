class Solution {
    private boolean isIdentical(TreeNode s, TreeNode t) {
        if (s == null && t == null)
            return true;
        if (s == null && t != null)
            return false;
        if (s != null && t == null)
            return false;
        if (s.val != t.val)
            return false;

        return isIdentical(s.left, t.left) && isIdentical(s.right, t.right);
    }

    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        Stack<TreeNode> st = new Stack<>();
        st.push(root);
        TreeNode temp = root;
        while (!st.empty()) {
            TreeNode n = st.peek();
            st.pop();

            if (n.val == subRoot.val) {
                if (isIdentical(n, subRoot) == true)
                    return true;
            }
            if (n.right != null)
                st.push(n.right);
            if (n.left != null)
                st.push(n.left);

        }

        return false;
    }
}
