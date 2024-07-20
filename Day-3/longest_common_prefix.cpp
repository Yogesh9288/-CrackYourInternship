class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string comm="";
        for(int i=0;i<strs[0].size();i++)
        {
            int flag=1;
            for(auto it:strs)
            {
                if(it[i]!=strs[0][i])
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
                comm+=strs[0][i];
            else break;
        }

        return comm;
    }
};
