class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int n=arr.size();
        int i=0,j=0;

        while(j<n)
        {
           if(arr[j]!=0) swap(arr[i++],arr[j]);
            j++;
        }


    }
};
