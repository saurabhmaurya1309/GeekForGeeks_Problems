//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++

class Solution{
public:
 void dfs(int node,vector<int>adj[101],vector<int>&vis){
        vis[node]=1;
        // cout<<node<<" ";
        for(auto child:adj[node]){
            if(!vis[child])dfs(child,adj,vis);
        }
    }
    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph)
    {
        // code here
        vector<int> adj[101];
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(graph[i][j]==1 && i!=j)
                    adj[i].push_back(j);
            }
        }
        vector<vector<int>> dp(N,vector<int>(N,0));
        vector<int>vis(N,0),hc(N,0);
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++)vis[j]=0;
            if(!vis[i])
            dfs(i,adj,vis);
            // for()
            for(int j=0;j<N;j++)dp[i][j]=vis[j];
        }
        return dp;
    
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for(int i = 0;i < N;i++)
            for(int j=0;j<N;j++)
            cin>>graph[i][j];
        
        Solution ob;
        vector<vector<int>> ans = ob.transitiveClosure(N, graph);
        for(int i = 0;i < N;i++)
            {for(int j = 0;j < N;j++)
                cout<<ans[i][j]<<" ";
        cout<<"\n";}
    }
    return 0;
}
// } Driver Code Ends