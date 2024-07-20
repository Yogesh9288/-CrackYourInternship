class Solution {
  void helper(List<String>ans,int o,int c,int n,String s)
  {
     if(o==n&&c==n)
     {
        ans.add(s);
        return ;
     }
     if(o<n)
     helper(ans,o+1,c,n,s+'(');
     if(c<o)
     helper(ans,o,c+1,n,s+')');
  }
  List<String> generateParenthesis(int n) {
     List<String>ans=[];
     helper(ans,0,0,n,"");
     return ans;
  }
}
