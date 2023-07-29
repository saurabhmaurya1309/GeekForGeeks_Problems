//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDropRec(int n, int k,vector<vector<int>>&dp){
        if(k == 0 || k == 1)
            return k;
        if(n == 1)
            return k;
        
        if(dp[n][k]!=-1){
            return dp[n][k];
        }
        int mn = INT_MAX, x, res;
        
        for(x = 1; x <= k; x++){
            res = 1+max(eggDropRec(n-1, x-1,dp), eggDropRec(n, k-x,dp));
            
            mn = min(mn, res);
        }
        dp[n][k]=mn;
        return dp[n][k];
    }
    int eggDrop(int n, int k) 
    {
        // your code here
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return eggDropRec(n,k,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends