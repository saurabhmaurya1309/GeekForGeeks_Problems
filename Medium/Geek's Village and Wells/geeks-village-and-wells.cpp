//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &c){
    // Code here
    vector<vector<int>> ans(n, vector<int>(m, -1));
    
    queue<int> q;
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(c[i][j] == 'W') {
                q.push(i * m + j);
                ans[i][j] = 0;
            }
        }
    }
    int steps = 2;
    
    vector<vector<int>> dirs = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };
    
    while(!q.empty()) {
        int size = q.size();
        
        while(size--) {
            int curr = q.front(); q.pop();
            
            int currX = curr / m;
            int currY = curr % m;
            
            for(int k = 0; k < 4; ++k) {
                int nextX = currX + dirs[k][0];
                int nextY = currY + dirs[k][1];
                
                if(nextX >= 0 && nextX < n && nextY >= 0 && nextY < m && ans[nextX][nextY] == -1) {
                    if(c[nextX][nextY] == 'H') {
                        ans[nextX][nextY] = steps;
                        q.push(nextX * m + nextY);
                    }
                    else if(c[nextX][nextY] == '.') {
                        ans[nextX][nextY] = 0;
                        q.push(nextX * m + nextY);
                    }
                }
            }
        }
        steps += 2;
    }
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(c[i][j] == 'N' || c[i][j] == '.') {
                ans[i][j] = 0;
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
        int n,m;
        cin>>n>>m;
        vector<vector<char>> c(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res=ob.chefAndWells(n,m,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
// } Driver Code Ends