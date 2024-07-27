//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
   void dfs(vector<vector<char>> &mat,int n,int m,int i,int j,vector<vector<int>>&vis)
   {
       if(i<0||j<0||i>n-1||j>m-1||vis[i][j]==1||mat[i][j]=='X') return;
       
       vis[i][j]=1;
       
       dfs(mat,n,m,i+1,j,vis);
        dfs(mat,n,m,i-1,j,vis);
         dfs(mat,n,m,i,j+1,vis);
          dfs(mat,n,m,i,j-1,vis);
   }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++)
        {
            if(mat[0][i]=='O'&&vis[0][i]==0) dfs(mat,n,m,0,i,vis);
        }
        for(int i=0;i<m;i++)
        {
            if(mat[n-1][i]=='O'&&vis[n-1][i]==0) dfs(mat,n,m,n-1,i,vis);
        }
        for(int i=0;i<n;i++)
        {
            if(mat[i][0]=='O'&&vis[i][0]==0) dfs(mat,n,m,i,0,vis);
        }
           for(int i=0;i<n;i++)
        {
            if(mat[i][m-1]=='O'&&vis[i][m-1]==0) dfs(mat,n,m,i,m-1,vis);
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]=='O'&&vis[i][j]==0) mat[i][j]='X';
            }
        }
        
        return mat;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
