//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int solve(int i,int j,string A,string B,vector<vector<int>>&dp){
	       // cout<<"h";
	        if(i>=A.length()||j>=B.length()){
	           // cout<<"h";
	            return 0;
	        }
	       if(dp[i][j]!=-1){
	           return dp[i][j];
	       }     
	        if(A[i]==B[j]&&i!=j){
	           dp[i][j]=1+solve(i+1,j+1,A,B,dp);
	           return dp[i][j];
	        }  
	       else{
	            int ans1=0,ans2=0;
	            ans1=solve(i+1,j,A,B,dp);
	            ans2=solve(i,j+1,A,B,dp);
	            dp[i][j]= max(ans1,ans2); 
	            return dp[i][j];
	       }
	    }
	    int solveTab(string A){
	        string B=A;
	        int n=A.length();
	        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
	        for(int i=0;i<=n;i++){
	            dp[i][n]=0;
	            dp[n][i]=0;
	        }
	        for(int i=n-1;i>=0;i--){
	            for(int j=n-1;j>=0;j--){
	                 if(A[i]==B[j]&&i!=j)
	                    dp[i][j]=1+dp[i+1][j+1];
        	       else{
        	            int ans1=0,ans2=0;
        	            ans1=dp[i+1][j];
        	            ans2=dp[i][j+1];
        	            dp[i][j]= max(ans1,ans2); 
        	       }
	            }
	        }
	        return dp[0][0];
	        
	    }
		int LongestRepeatingSubsequence(string A){
		    // Code here
		  //  string B=A;
		  //  int n=A.length();
		  ////  cout<<B<<endl;
		  //  vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
		  //  return solve(0,0,A,B,dp);
		    return  solveTab( A);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends