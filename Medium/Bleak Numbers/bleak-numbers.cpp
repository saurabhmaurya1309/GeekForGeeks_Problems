//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	int is_bleak(int n)
	{
	      int mx = max(0,n-31); 
        int cnt= 0;
        for(int i = n-1; i>=mx; i--){
            int p =0;
            int k= i;
            cnt++; 
            while(k){
                p += (k%2);
                k /= 2;
            }
            if(p==cnt)return 0; 
        }
        return 1;
	}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends