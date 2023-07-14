//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    int solve(int i,int j, string &s1,string &s2,vector<vector<int>>&dp){
        if(i==s1.size()||j==s2.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s1[i]==s2[j]){
            return 1+solve(i+1,j+1,s1,s2,dp);
        }
        int ans1=solve(i+1,j,s1,s2,dp);
        int ans2=solve(i,j+1,s1,s2,dp);
        return dp[i][j]=max(ans1,ans2);
    }
    //Function to find the length of longest common subsequence in two strings.
    int solveTab(string s1,string s2,int n,int m){
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++){
            dp[i][m]=0;
        }
        for(int i=0;i<m;i++){
            dp[n][i]=0;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(s1[i]==s2[j]){
                    dp[i][j]=(1+dp[i+1][j+1]);
                    // cout<<dp[i][j]<<" "<<dp[i+1][j+1]<<endl;
                }
                else{
                int ans1=dp[i+1][j];
                int ans2=dp[i][j+1];
                
                dp[i][j]=max(ans1,ans2);
                }
            }
        }
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=m;j++){
        //         cout<<dp[i][j]<<" ";
        //     }cout<<endl;
        // }
        return dp[0][0];
        
    }
    int lcs(int n, int m, string s1, string s2)
    {
        // your code here
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return solve(0,0,s1,s2,dp);
        return solveTab(s1,s2,n,m);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends