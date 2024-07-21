class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int left = target - nums[i];
            if (mp.count(left) != 0)
                return {i, mp[left]};
            else
                mp[nums[i]] = i;
        }

        return {0, 0};
    }
};
