class Solution {
    private void solve(int[] candidates, int i, int target, List<List<Integer>> ans, List<Integer> temp) {
        if (target < 0)
            return;
        if (target == 0) {
            ans.add(new ArrayList<>(temp));
            return;
        }
        if (i == candidates.length)
            return;

        temp.add(candidates[i]);
        solve(candidates, i + 1, target - candidates[i], ans, temp);
        temp.remove(temp.size() - 1);
        int k = i;
        while (k < candidates.length && candidates[i] == candidates[k])
            k++;
        solve(candidates, k, target, ans, temp);
    }

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        int n = candidates.length;
        Arrays.sort(candidates);
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        solve(candidates, 0, target, ans, temp);

        return ans;
    }
}
