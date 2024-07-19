//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string s)
    {
        stack<int>st;
        
        for(auto &i:s)
        {
            if(!isdigit(i))
            {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                switch(i)
                {
                    case '+': st.push(a+b);
                            break;
                    case '-': st.push(b-a);
                            break;
                    case '*': st.push(a*b);
                            break;
                    case '/': st.push(b/a);
                            break;
                }
            }else st.push(i-'0');
        }
        
        
        return st.top();
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends
