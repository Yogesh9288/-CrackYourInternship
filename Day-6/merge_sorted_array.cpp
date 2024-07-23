class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> merge(m + n, 0);
        int i = 0, j = 0, k = 0;

        while (i < m && j < n) {
            if (nums1[i] < nums2[j])
                merge[k++] = nums1[i++];
            else
                merge[k++] = nums2[j++];
        }
        while (i < m)
            merge[k++] = nums1[i++];
        while (j < n)
            merge[k++] = nums2[j++];
        nums1 = merge;
    }
};
