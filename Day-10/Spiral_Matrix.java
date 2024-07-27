class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int minr = 0, maxr = m - 1, minc = 0, maxc = n - 1;
        List<Integer> ans = new ArrayList<>();
        int cnt = m * n;
        while (cnt != 0) {
            for (int i = minc; i <= maxc && cnt != 0; i++) {
                ans.add(matrix[minr][i]);
                cnt--;
            }
            minr++;
            for (int i = minr; i <= maxr && cnt != 0; i++) {
                ans.add(matrix[i][maxc]);
                cnt--;
            }
            maxc--;
            for (int i = maxc; i >= minc && cnt != 0; i--) {
                ans.add(matrix[maxr][i]);
                cnt--;
            }
            maxr--;
            for (int i = maxr; i >= minr && cnt != 0; i--) {
                ans.add(matrix[i][minc]);
                cnt--;
            }
            minc++;
        }

        return ans;
    }
}
