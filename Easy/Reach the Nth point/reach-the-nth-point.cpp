//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    int mod=1000000007;
		int nthPoint(int n){
		    // Code here
		   vector<int>arr(n+1);
		   arr[0]=1;
		   arr[1]=1;
		   for(int i=2;i<=n;i++){
		       arr[i]=(arr[i-1]+arr[i-2])%mod;
		   }
		    return arr[n];
		}
};


// } Driver Code Ends

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends