//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   
    int mod=100000;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if(start==end) return 0;
        vector<int>vis(1e5,0);
        // code here
        queue<pair<int,int>>q;
        q.push({start,0});
        
        while(!q.empty()){
            
            int x=q.front().first;
            int c=q.front().second;
            
            if(x==end) return c;
            q.pop();
            for(auto i : arr){
                
                if(!vis[(i*x)%mod]){
                    vis[(i*x)%mod]=1;
                    
                    q.push({(i*x)%mod,c+1});
                    
                }
             
            }
           
        }
       
        return -1;
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends