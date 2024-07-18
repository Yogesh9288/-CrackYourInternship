class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int idx=abs(nums[i]);

            if(nums[idx]<0) return abs(idx);
            else nums[idx]*=-1;
        }

        return 0;
    }
};
