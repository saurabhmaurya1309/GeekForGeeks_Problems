//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	 int solveMem(int n,int a[],int curr,int prev,vector<vector<int>>&dp){
        if(curr==n){
            return 0;
        }
        // include
        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }
        int take=0;
        if(prev==-1||a[curr]>a[prev]){
            take=a[curr]+solveMem(n,a,curr+1,curr,dp);
        }
        // exclude
        int nottake=0+solveMem(n,a,curr+1,prev,dp);
        
        return dp[curr][prev+1]=max(take,nottake);
    }
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<vector<int>>dp(n,vector<int>(n+1,-1));
	    return solveMem(n,arr,0,-1,dp);
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends