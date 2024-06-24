//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int solve(vector<int>&coins,int n,int target){
	    if(target==0){
	        return 0;
	    }
	    if(target<0){
	        return 999999;
	    }
	    int mini=INT_MAX;
	    for(int i=0;i<n;i++){
	        int ans=1+solve(coins,n,target-coins[i]);
	        mini=min(ans,mini);
	    }
	    return mini;
	}
	int solveTab(vector<int>&coins,int n,int target,vector<int>&dp){
	    if(target==0){
	        return 0;
	    }
	    if(target<0){
	        return 999999;
	    }
	    if(dp[target]!=0){
	        return dp[target];
	    }
	    int mini=INT_MAX;
	    for(int i=0;i<n;i++){
	        int ans=1+solveTab(coins,n,target-coins[i],dp);
	        mini=min(ans,mini);
	    }
	    return dp[target]=mini;
	}
	int minCoins(vector<int> &coins, int M, int V) 
	{ 
	    // Your code goes here
	   // int ans=solve(coins,M,V);
	   // return ans;
	   vector<int>dp(V+1,0);
	   int ans=solveTab(coins,M,V,dp);
	   if(ans>=999999){
	       return -1;
	   }
	   return ans;
	   
	} 
	  
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        vector<int> coins(m);
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends