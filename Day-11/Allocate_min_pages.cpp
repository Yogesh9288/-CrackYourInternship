//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m) {
        if(m>n) return -1;
        int sum=accumulate(arr,arr+n,0);
        int max=*max_element(arr,arr+n);
        
        long long low=max;
        long long high=sum;
        
        while(low<=high)
        {
            long long mid=low+(high-low)/2;
            int cnt=1,pages=0;
            for(int i=0;i<n;i++)
            {
                if(pages+arr[i] <=mid) pages+=arr[i];
                else{
                    cnt++;
                    pages=arr[i];
                }
                
            }
            
            
            if(cnt>m) low=mid+1;
            else high=mid-1;
        }
        
        
        return low;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends
