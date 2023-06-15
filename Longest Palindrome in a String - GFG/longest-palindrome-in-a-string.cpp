//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int start = -1;
    int end = -1;
    int ansLen = 0;
    string longestPalin (string S) {
        for(int i=0; i<S.length(); i++){
            int s = i;
            int e = i;
            while(s >= 0 && e < S.length()){
                if(S[s] == S[e]){
                    if(ansLen < e-s+1){
                        ansLen = e-s+1;
                        start = s;
                        end = e;
                    }
                }
                else{
                    break;
                }
                s--;
                e++;
            }
            s = i;
            e = i+1;
            while(s >= 0 && e < S.length()){
                if(S[s] == S[e]){
                    if(ansLen < e-s+1){
                        ansLen = e-s+1;
                        start = s;
                        end  = e;
                    }
                }
                else{
                    break;
                }
                s--;
                e++;
            }
        }
        string ans = "";
        for(int i=start; i<=end; i++){
            ans += S[i];
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends