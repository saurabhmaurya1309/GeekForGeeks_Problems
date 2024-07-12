//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int cal(int a[],int i,int n,int sum){
      if(i>=n){
          return sum;
      }
      return cal(a,i+1,n,sum+a[i]);
  }
    int mean(int N , int A[]) {
        // code here
        int ans=cal(A,0,N,0);
        return ans/N;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        int A[N];
        for(int i=0 ; i<N ; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.mean(N,A) << endl;
    }
    return 0;
}
// } Driver Code Ends