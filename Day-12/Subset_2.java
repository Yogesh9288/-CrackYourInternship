class Solution {
    private void solve(int[] nums, int i, List<List<Integer>> ans, List<Integer> temp) {
        if (i == nums.length) {
            ans.add(new ArrayList<>(temp));
            return;
        }

        temp.add(nums[i]);
        solve(nums, i + 1, ans, temp);
        temp.remove(temp.size() - 1);
        int j = i;
        while (j < nums.length && nums[j] == nums[i])
            j++;
        solve(nums, j, ans, temp);
    }

    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<>();
        ;
        List<Integer> temp = new ArrayList<>();
        solve(nums, 0, ans, temp);

        return ans;
    }
}
