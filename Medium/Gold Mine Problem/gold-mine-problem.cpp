//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
         vector<vector<int>> result (n+2 ,vector<int>(m+1 ,0));
        
        for(int col=0;col<m;col++){
            for(int row=0 ;row<n;row++){
                int maxi = max(result[row][col] ,result[row+1][col] );
              result[row+1][col+1]= M[row][col] + max(maxi ,result[row+2][col]); 
            }
        }
        int ans =0;
        for(int i=1;i<=n;i++){
            ans=max(result[i][m] ,ans);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends