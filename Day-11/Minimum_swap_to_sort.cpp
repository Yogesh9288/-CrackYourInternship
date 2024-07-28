//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    
	    vector<pair<int,int>>temp;
	    for(int i=0;i<nums.size();i++) temp.push_back({nums[i],i});
	    sort(temp.begin(),temp.end());
	    
	    int s=0;
	    
	    for(int i=0;i<nums.size();i++)
	    {
	        if(temp[i].second==i) continue;
	        else{
	            s++;
	            swap(temp[i],temp[temp[i].second]);
	            i--;
	        }
	        
	    }
	    
	    
	    return s;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
