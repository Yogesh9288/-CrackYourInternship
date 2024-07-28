class Solution {
  int findPeakElement(List<int> nums) {
    int n=nums.length;
    int low=0;
    int high=n-1;

    while(low<=high)
    {
        int mid=(low+(high-low)/2).toInt();

        if((mid==0||nums[mid]>nums[mid-1])&&(mid==n-1||nums[mid]>nums[mid+1])) return mid;
        else if(mid==0||nums[mid]>nums[mid-1]) low=mid+1;
        else high=mid-1;
    }

    return 0;

  }
}
