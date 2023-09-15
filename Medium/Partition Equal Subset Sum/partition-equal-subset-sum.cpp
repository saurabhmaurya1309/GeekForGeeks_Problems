//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int index,int arr[],int N,int target){
        if(target<0){
            return 0;
        }
        if(index>=N){
            return 0;
        }
        if(target==0){
            return 1;
        }
        int include=solve(index+1,arr,N,target-arr[index]);
        int exclude=solve(index+1,arr,N,target);
        return (include||exclude);
    }
    
    int solveMem(int index,int arr[],int N,int target,vector<vector<int>>&dp){
        if(target<0){
            return 0;
        }
        if(index>=N){
            return 0;
        }
        if(target==0){
            return 1;
        }
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        int include=solveMem(index+1,arr,N,target-arr[index],dp);
        int exclude=solveMem(index+1,arr,N,target,dp);
       dp[index][target]= (include||exclude);
       return dp[index][target];
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int total=0;
        for(int i=0;i<N;i++){
            total+=arr[i];
        }
        if(total&1)
            return 0;
        int target=total/2;
        // return solve(0,arr,N,target);
        vector<vector<int>>dp(N,vector<int>(target+1,-1));
        return solveMem(0,arr,N,target,dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends