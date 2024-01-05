//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	const long long MOD = 1e9 + 7;
        int findWays(int n, vector<int>& dp) {
            if(n <= 1) return dp[n];
            
            if(dp[n] != -1) return dp[n];
            
            return dp[n] = (findWays(n-1, dp) % MOD + findWays(n-2, dp) % MOD) % MOD;
        }
	int TotalWays(int N)
	{
	    // Code here
	       vector<int> dp(N+1, -1);
        dp[0] = 1;
        dp[1] = 2;
        
        long long ans = findWays(N, dp);
        return (ans * ans) % MOD;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends