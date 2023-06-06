//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  void fun(int arr[],int size){
      arr[1]=1;
      for(int i=2;i<size;i++){
          for(int j=i;j<size;j+=i){
              if(arr[j]==0){
                  arr[j]=i;
              }
          }
      }
  }
    vector<int> leastPrimeFactor(int n) {
          vector<int>v(n+1);
        v[0]=0;
        int arr[n+1]={0};
        fun(arr,n+1);
        
        for(int i=1;i<n+1;i++){
            v[i]=arr[i];
        }
        return v;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends