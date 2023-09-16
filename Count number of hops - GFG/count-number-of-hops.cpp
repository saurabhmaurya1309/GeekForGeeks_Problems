//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
   long long solve(int i, vector<long long>&dp)
   {
       if(i==0)
        return 1;
       if(i<0)
        return 0;
       
       if(dp[i]!=-1)
         return dp[i];
       
       dp[i]=(solve(i-1,dp)%1000000007+ solve(i-2,dp)%1000000007+solve(i-3,dp)%1000000007)%1000000007;
       return dp[i];
        
   }
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        
        // your code herr
if(n==0)
 return 4;
      vector<long long>dp(n+1,-1);
      long long ans=solve(n,dp);
      return ans;
        
    }
};



//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends