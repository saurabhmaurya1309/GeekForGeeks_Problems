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
    int solveTab(string s,string t){
        vector<vector<int>>dp(s.length()+1,vector<int>(t.length()+1,0));
        for(int j=0;j<t.length();j++){
            dp[s.length()][j]=t.length()-j;
        }
        for(int i=0;i<s.length();i++){
            dp[i][t.length()]=s.length()-i;
        }
        for(int i=s.length()-1;i>=0;i--){
               for(int j=t.length()-1;j>=0;j--){
                    int ans=0;
                    if(s[i]==t[j]){
                        ans=dp[i+1][j+1];
                    }   
                    else{
                        // insert
                        int insertAns=1+dp[i][j+1];
                        
                        // delete
                        int removeAns=1+dp[i+1][j];
                        // replace
                        int replaceAns=1+dp[i+1][j+1];
                        ans=min(insertAns,min(removeAns,replaceAns));
                    }
                      dp[i][j]=ans;
            
                }
        }
        return dp[0][0];
        
    }
    
    
    int  optimize(string s,string t){
        vector<int>curr(t.length()+1,0);
        vector<int>next(t.length()+1,0);
        
        for(int j=0;j<t.length();j++){
            next[j]=t.length()-j;
        }
       
        for(int i=s.length()-1;i>=0;i--){
               for(int j=t.length()-1;j>=0;j--){
                   curr[t.length()]=s.length()-i;
                    int ans=0;
                    if(s[i]==t[j]){
                        ans=next[j+1];
                    }   
                    else{
                        // insert
                        int insertAns=1+curr[j+1];
                        
                        // delete
                        int removeAns=1+next[j];
                        // replace
                        int replaceAns=1+next[j+1];
                        ans=min(insertAns,min(removeAns,replaceAns));
                    }
                      curr[j]=ans;
            
                }
                next=curr;
        }
        return next[0];
        
        
        
    }
    
    
    
    
    
    int editDistance(string s, string t) {
        // Code here
        // int n=s.length();
        // int m=t.length();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return solve(0,0,s,t,dp);
        
        
       return optimize(s,t);
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