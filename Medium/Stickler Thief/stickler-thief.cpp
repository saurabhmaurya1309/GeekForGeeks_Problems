//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int solve(int arr[], int n){
        if(n<0)
            return 0;
        if(n==0){
            return arr[0];
        } 
        int incl=solve(arr,n-2)+arr[n];
        int excl=solve(arr,n-1)+0;
        return max(incl,excl);
    }
    int solveMem(int arr[], int n,vector<int>&dp){
        if(n<0)
            return 0;
        if(n==0){
            return arr[0];
        } 
        if(dp[n]!=-1)
            return dp[n];
        int incl=solveMem(arr,n-2,dp)+arr[n];
        int excl=solveMem(arr,n-1,dp)+0;
        dp[n]=max(incl,excl);
        return dp[n];
    }
    // int solvetab(int arr[], int n){
       
    //     vector<int>dp(n,0);
    //     dp[0]=arr[0];
    //     for(int i=1;i<n;i++){
    //         int incl=dp[i-2]+arr[i];
    //         int excl=dp[i-1];
    //         dp[i]=max(incl,excl);
    //     }
    //     return dp[n-1];
    // }
    int op(int arr[], int n){
       
        int prev2=0;
        int prev1=arr[0];
        for(int i=1;i<n;i++){
            int incl=prev2+arr[i];
            int excl=prev1;
            int ans=max(incl,excl);
            prev2=prev1;
            prev1=ans;
        }
        return prev1;
    }
   
    
    int FindMaxSum(int arr[], int n)
    {
    //   int ans=solve(arr,n-1);
    //   return ans;
    // using dp
    // vector<int>dp(n,-1);
    // int ans=solveMem(arr,n-1,dp);
    // return ans;
    // }
    // by tabulation
    // int ans=solvetab(arr,n);
    // return ans;
    // }
    
    // space optimization
    int ans=op(arr,n);
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