class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> ls = new ArrayList<>();
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            int idx = Math.abs(nums[i]);
            if (nums[idx - 1] < 0)
                ls.add(Math.abs(nums[i]));
            else
                nums[idx - 1] *= -1;
        }

        return ls;
    }
}
