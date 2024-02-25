//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int solve(int i,int arr[],int n){
        if(i>=n){
            return 0;
        }
        int include=arr[i]+solve(i+2,arr,n);
        int exclude=solve(i+1,arr,n);
        int ans=max(include,exclude);
        return ans;
    }
    int solveMem(int i,int arr[],int n,vector<int>&dp){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int include=arr[i]+solveMem(i+2,arr,n,dp);
        int exclude=solveMem(i+1,arr,n,dp);
        dp[i]=max(include,exclude);
        return dp[i];
    }
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        // return solve(0,arr,n);
        vector<int>dp(n+1,-1);
        return solveMem(0,arr,n,dp);
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
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends