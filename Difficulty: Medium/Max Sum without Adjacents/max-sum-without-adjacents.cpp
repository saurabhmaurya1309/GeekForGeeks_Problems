//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int solve(int *arr,int start,int n,vector<int>&dp){
	    if(start==n-1){
	        return arr[n-1];
	    }
	    if(start>=n){
	        return 0;
	    }
	    if(dp[start]!=-1){
	        return dp[start];
	    }
	    int take=arr[start]+solve(arr,start+2,n,dp);
	    int nottake=solve(arr,start+1,n,dp);
	    return dp[start]=max(take,nottake);
	}
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int>dp(n+1,-1);
	    return solve(arr,0,n,dp);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends