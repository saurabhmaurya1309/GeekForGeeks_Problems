//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:
    string rremove(string s){
        // code here
         string res = "";
        int n = s.length();
        
        int i=0;
        while(i<n){
           if(i<n-1&&s[i]==s[i+1]){
               while(i<n-1&&s[i]==s[i+1]){
                   i++;
               }
           }
               else{
                   res+=s[i];
               }
               i++;
        }
        
        if(res == s)
            return res;
        return rremove(res);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.rremove(s) << "\n";
    }
    return 0;
}
// } Driver Code Ends