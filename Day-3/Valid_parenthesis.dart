class Solution {
  bool isValid(String s) {
       List<String>ls=[];

       for(int i=0;i<s.length;i++)
       {
          if(s[i]=='('||s[i]=='{'||s[i]=='[') ls.add(s[i]);
          else{
            if(ls.isEmpty) return false;
            if((s[i]==')'&&ls.last=='(')||(s[i]=='}'&&ls.last=='{')||(s[i]==']'&&ls.last=='[')) ls.removeLast();
            else return false;
          }
       }

       return ls.isEmpty;
  }
}
