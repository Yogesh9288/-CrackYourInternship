class Solution {
  List<int> dailyTemperatures(List<int> temp) {
    int n=temp.length;
    List<int>ans=List.filled(n,0);
    List<int>stack=[];
    for(int i=0;i<n;i++)
    {
        while(!stack.isEmpty&&temp[stack.last]<temp[i])
        {
            ans[stack.last]=i-stack.last;
            stack.removeLast();
        }
        stack.add(i);
    }


    return ans;
  }
}
