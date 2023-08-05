//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int lcs(string s1,string s2,int i,int j,vector<vector<int>>&dp){
        if(i==s1.length()||j==s2.length()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s1[i]==s2[j]){
            return dp[i][j]=1+lcs(s1,s2,i+1,j+1,dp);
        }
        else{
            int ans1=lcs(s1,s2,i+1,j,dp);
            int ans2=lcs(s1,s2,i,j+1,dp);
            return dp[i][j]=max(ans1,ans2);
        }
    }
    int countMin(string str){
        string rstr=str;
        int n=str.length();
        reverse(rstr.begin(),rstr.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int x=lcs(str,rstr,0,0,dp);
        return str.length()-x;
    
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends