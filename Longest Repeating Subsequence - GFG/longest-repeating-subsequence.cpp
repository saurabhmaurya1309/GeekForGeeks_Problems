//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	   
	    int space(string A){
	        string B=A;
	         int n=A.length();
	       vector<int>curr(n+1,0);
	       vector<int>next(n+1,0);
	      
	        for(int i=n-1;i>=0;i--){
	            for(int j=n-1;j>=0;j--){
	                 if(A[i]==B[j]&&i!=j)
	                    curr[j]=1+next[j+1];
        	       else{
        	            int ans1=0,ans2=0;
        	            ans1=next[j];
        	            ans2=curr[j+1];
        	            curr[j]= max(ans1,ans2); 
        	       }
	            }
	            next=curr;
	        }
	        return next[0];
	    }
		int LongestRepeatingSubsequence(string A){
		  
		    return  space( A);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends