//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int fib(long long int n, vector<long long int>&dp){
        if(n<=1)
            return n;
        if(dp[n]!=-1)
            return dp[n];
        dp[n] =(fib(n-1,dp)+fib(n-2,dp))%1000000007;  
        return dp[n];
        
    }
    long long int nthFibonacci(long long int n){
        // code here
         vector<long long int>dp(n+1,-1);
    //   return fib(n,dp);
    
        // 2nd approach using tabulatio
        // dp[0]=0;
        // dp[1]=1;
        // for(int i=2;i<=n;i++){
        //     dp[i]=(dp[i-1]+dp[i-2])%1000000007;
        // }
        // return dp[n];
        
        // 3rd approach constant space
        long long int prev1=0;
        long long int prev2=1;
        for(int i=2;i<=n;i++){
            int curr=(prev1+prev2)%1000000007;
            prev1=prev2;
            prev2=curr;
        }
        return prev2;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends