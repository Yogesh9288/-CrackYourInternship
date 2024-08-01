class Solution {
    public int climbStairs(int n) {
        if (n <= 1)
            return 1;

        int one = 1;
        int two = 1;
        int three = 0;

        for (int i = 2; i <= n; i++) {
            three = one + two;
            one = two;
            two = three;
        }

        return three;
    }
}
