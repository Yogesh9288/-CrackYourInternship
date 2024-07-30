//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    bool dfs(bool graph[101][101],int m,int node,int n,vector<int>&color)
    {
        if(node==n) return true;
        
        for(int i=0;i<m;i++)
        {
            bool isPossible=true;
            for(int j=0;j<n;j++)
            {
                if(graph[node][j]==1&&color[j]==i) 
                {
                    isPossible=false;
                    break;
                }
            }
            
            if(isPossible)
            {
                color[node]=i;
                if(dfs(graph,m,node+1,n,color)) return true;
                color[node]=-1;
            }
            
        }
        
        return false;
    }
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
         vector<int>color(n,-1);
         
         return dfs(graph,m,0,n,color);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
