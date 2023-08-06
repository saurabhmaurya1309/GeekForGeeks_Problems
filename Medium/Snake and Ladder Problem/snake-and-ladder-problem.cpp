//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int N, int arr[]){
        // code here
        vector<int>grid(30,0);
        for(int i=0;i<N;i+=2){
            grid[arr[i]-1]=arr[i+1]-1;
        }
        for(int i=N;i<2*N;i+=2){
            grid[arr[i]-1]=arr[i+1]-1;
        }
        //  
        queue<pair<int,int>>q;
        q.push({0,0});
        vector<int>vis(30,0);
        vis[0]=1;
        int ans=1e9;
        while(!q.empty()){
            auto it=q.front();
            int node=it.first;
            int step=it.second;
            q.pop();
            if(node==29){
                ans=min(ans,step);
            }
            for(int i=1;i<7;i++){
                int newnode=node+i;
                if(newnode<30&& vis[newnode]==0){
                    vis[newnode]=1;
                    if(grid[newnode]!=0){
                        
                    q.push({grid[newnode],step+1});
                    }
                    else{
                        q.push({newnode,step+1});
                    }
                }
            }
            
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends