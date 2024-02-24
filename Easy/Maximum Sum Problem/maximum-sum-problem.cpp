//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
      int maxSum(int n)
        {
            //code here.
             
            if(n==0)
            return 0;
            
            int sum=maxSum(n/2)+maxSum(n/3)+maxSum(n/4);
            if(sum>=n)return sum;
            else return n;
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends