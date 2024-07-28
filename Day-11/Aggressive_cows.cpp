//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    int solve(int n, int k, vector<int> &stalls) {
    
        int minD=INT_MAX;
        int maxD=INT_MIN;
        sort(stalls.begin(),stalls.end());
        for(int i=1;i<n;i++) minD=min(minD,stalls[i]-stalls[i-1]);
        maxD=stalls[n-1]-stalls[0];
        
        long long low=minD;
        long long high=maxD;
        
        
        while(low<=high)
        {
            long long mid=low+(high-low)/2;
            int cnt=1,last=stalls[0];
            for(int i=1;i<n;i++)
            {
                if(stalls[i]-last > mid)
                {
                    cnt++;
                    last=stalls[i];
                }
            }
            
            if(cnt>=k) low=mid+1;
            else high=mid-1;
            
            
        }
        
        
        return low;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends
