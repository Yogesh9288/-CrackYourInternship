class Solution {
    private void solve(int n, int k, int i, List<List<Integer>> ans, List<Integer> temp) {
        if (temp.size() == k) {
            ans.add(new ArrayList<>(temp));
            return;
        }
        if (i > n)
            return;

        temp.add(i);
        solve(n, k, i + 1, ans, temp);
        temp.remove(temp.size() - 1);
        solve(n, k, i + 1, ans, temp);
    }

    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> ans = new ArrayList<>();
        ;
        List<Integer> temp = new ArrayList<>();
        solve(n, k, 1, ans, temp);

        return ans;
    }
}
