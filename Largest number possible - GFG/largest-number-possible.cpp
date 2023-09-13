//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        // code here
        int cnt=0;
        string ans="";
        if(S==0&&N!=1){
            return "-1";
        }
        while(S||ans.length()<N){
            if(ans.length()==N&&S!=0){
                return "-1";
            }
            if(S>9){
                ans+='9';
                S-=9;
            }
            else if(S>0){
                ans+=to_string(S);
                S=0;
            }
            else{
                ans+='0';
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
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends