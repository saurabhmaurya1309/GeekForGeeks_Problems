//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solve(int W, int wt[], int val[], int index){
        if(index==0){
            if(wt[0]<=W){
                return val[0];
            }
            else{
                return 0;
            }
        }
        int include=0;
        if(wt[index]<=W){
            include=val[index]+solve(W-wt[index],wt,val,index-1);
        }
        int exclude=solve(W,wt,val,index-1);
        int ans=max(exclude,include);
        return ans;
    }
    int solveMem(int W, int wt[], int val[], int index, vector<vector<int>>&dp){
        if(index==0){
            if(wt[0]<=W){
                return val[0];
            }
            else{
                return 0;
            }
        }
        if(dp[index][W]!=-1){
            return dp[index][W];
        }
        int include=0;
        if(wt[index]<=W){
            include=val[index]+solveMem(W-wt[index],wt,val,index-1,dp);
        }
        int exclude=solveMem(W,wt,val,index-1,dp);
        dp[index][W]=max(exclude,include);
        return dp[index][W];
    }
    int solveTab(int W,int wt[],int val[],int n){
        vector<vector<int>>dp(n,vector<int>(W+1,0));
        for(int i=wt[0];i<=W;i++){
            if(wt[0]<=W){
                dp[0][i]=val[0];
            }
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=W;j++){
               int include=0;
                if(wt[i]<=j){
                    include=val[i]+dp[i-1][j-wt[i]];
                }
                int exclude=dp[i-1][j];
                dp[i][j]=max(exclude,include);
               
            }
        }
         return dp[n-1][W]; 
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
    //   int ans=solve(W,wt,val,n-1);
    // vector<vector<int>>dp(n,vector<int>(W+1,-1));
    // int ans=solveMem(W,wt,val,n-1,dp);
    //   return ans;
        return solveTab(W,wt,val,n);
       
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
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends