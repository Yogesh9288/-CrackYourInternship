class Solution {
public:
    TreeNode* construct(vector<int>& nums, int l, int h) {
        if (l > h)
            return NULL;
        int m = l + (h - l) / 2;
        TreeNode* node = new TreeNode(nums[m]);
        node->left = construct(nums, l, m - 1);
        node->right = construct(nums, m + 1, h);

        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = construct(nums, 0, nums.size() - 1);
        return root;
    }
};
