class Solution {

    int maxRectangle(int arr[]) {
        int ans = 0;
        int r = 0;
        int n = arr.length;
        int maxh = 0;
        Stack<Integer> st = new Stack<>();
        for (int i = 0; i < arr.length; i++) {
            while (!st.empty() && arr[st.peek()] > arr[i]) {
                r = st.peek();
                st.pop();
                if (!st.empty()) {
                    ans = arr[r] * (i - st.peek() - 1);
                } else {
                    ans = arr[r] * i;
                }

                maxh = Math.max(maxh, ans);
            }

            st.push(i);
        }

        while (!st.empty()) {
            r = st.peek();
            st.pop();
            if (!st.empty()) {
                ans = arr[r] * (n - st.peek() - 1);
            } else {
                ans = arr[r] * n;
            }

            maxh = Math.max(maxh, ans);
        }

        return maxh;

    }

    public int maximalRectangle(char[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int a[] = new int[n];
        Arrays.fill(a, 0);
        int maxr = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '0')
                    a[j] = 0;
                else
                    a[j]++;
            }

            maxr = Math.max(maxr, maxRectangle(a));
        }

        return maxr;
    }
}
