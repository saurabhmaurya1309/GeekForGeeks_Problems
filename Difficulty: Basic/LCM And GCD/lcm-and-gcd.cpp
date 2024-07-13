//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long findgcd(long long A,long long B){
        if(A==0)return B;
        if(B==0)return A;
        while (B != 0) {
        long long temp = B;
        B = A % B;
        A = temp;
        }
        return A;
    }
    
        
    
    vector<long long> lcmAndGcd(long long A , long long B) {
        // code here
        long long ans2=findgcd(A,B);
        long long ans1=A*B;
        ans1=ans1/ans2;
        return {ans1,ans2};
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends