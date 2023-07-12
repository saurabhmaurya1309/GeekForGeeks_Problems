//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int solve(int i,int j,string &s,string &t,vector<vector<int>>&dp){
        
        if(i==s.length()){
            return t.length()-j;
        }
        if(j==t.length()){
            return s.length()-i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(s[i]==t[j]){
            return solve(i+1,j+1,s,t,dp);
        }
        else{
            // insert
            int insertAns=1+solve(i,j+1,s,t,dp);
            
            // delete
            int removeAns=1+solve(i+1,j,s,t,dp);
            // replace
            int replaceAns=1+solve(i+1,j+1,s,t,dp);
            ans=min(insertAns,min(removeAns,replaceAns));
        }
        
        return dp[i][j]=ans;
    }
    int editDistance(string s, string t) {
        // Code here
        int n=s.length();
        int m=t.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(0,0,s,t,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends