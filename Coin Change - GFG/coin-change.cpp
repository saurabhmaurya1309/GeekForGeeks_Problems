//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    long long int solveTab(int coins[],int n,int sum){
         vector<vector<long long int>>dp(n+1,vector<long long int>(sum+1,0));
         for(int i=0;i<=n;i++){
             dp[i][0]=1;
         }
         
         for(int i=0;i<n;i++){
            //  cout<<"h";
             for(int j=1;j<=sum;j++){
                 long long int include=0;
                //  cout<<j-coins[i]<<endl;
                 if(j-coins[i]>=0)
                  include=dp[i][j-coins[i]];
                //   cout<<include<<endl;
                 long long int exclude=0;
                 if(i-1>=0)
                  exclude=dp[i-1][j];
                 dp[i][j]=include+exclude;
             }
         }
        //  for(int i=0;i<n;i++){
        //     //  cout<<"h";
        //      for(int j=0;j<=sum;j++){
        //         cout<<dp[i][j]<<" ";
        //      }cout<<endl;
        //  }
         
         return dp[n-1][sum];
         
    }
       
    long long int count(int coins[], int N, int sum) {

        
        vector<vector<long long int>>dp(N+1,vector<long long int>(sum+1,-1));
        return solveTab(coins,N,sum);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends