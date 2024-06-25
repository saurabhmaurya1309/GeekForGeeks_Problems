//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int solve(int arr[],int n,int i){
        if(i>=n){
            return 0;
        }
        if(i==n-1){
            return arr[i];
        }
        int incl=solve(arr,n,i+2)+arr[i];
        int excl=solve(arr,n,i+1);
        int ans=max(incl,excl);
        return ans;
    }
    int solveMem(int arr[],int n,int i,vector<int>&dp){
        if(i>=n){
            return 0;
        }
        if(i==n-1){
            return arr[i];
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int incl=solveMem(arr,n,i+2,dp)+arr[i];
        int excl=solveMem(arr,n,i+1,dp);
        int ans=max(incl,excl);
        dp[i]=ans;
        return ans;
    }
    
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        // int ans=solve(arr,n,0);
        // return ans;
        vector<int>dp(n+1,-1);
        int ans=solveMem(arr,n,0,dp);
        return ans;
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