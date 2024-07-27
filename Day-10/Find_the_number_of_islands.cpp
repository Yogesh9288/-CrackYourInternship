//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(vector<vector<char>>& grid, vector<vector<int>>&directions,int i,int j, vector<vector<int>>&vis)
    {
        int m=grid.size();
        int n=grid[0].size();
        
        if(i<0||j<0||i>m-1||j>n-1||vis[i][j]==1||grid[i][j]=='0') return;
        
        vis[i][j]=1;
        
        for(auto &it:directions)
        {
            int x=i+it[0];
            int y=j+it[1];
            dfs(grid,directions,x,y,vis);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int cnt=0;
        vector<vector<int>>directions={{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j]&&grid[i][j]=='1')
                {
                    dfs(grid,directions,i,j,vis);
                    cnt++;
                }
            }
        }
        
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends
