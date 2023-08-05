//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long int solve(int n,vector<int>&dp){
        if(n<=6){
            return dp[n]=n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        long long int  ans=0;
        for(int i=n-3;i>=1;i--){
            long long int curr=(n-i-1)*solve(i,dp);
            ans=max(ans,curr);
           
        }
        return dp[n]=ans;
    }
    long long int optimalKeys(int N){
            vector<int>dp(N+1,-1);
          return solve(N,dp);
      
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.optimalKeys(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends