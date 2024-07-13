//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    string removeChars(string string1, string string2) {
        // code here
        vector<bool>visited(26,false);
        for(int i=0;i<string2.length();i++){
            int id=string2[i]-'a';
            if(!visited[id]){
                visited[id]=true;
            }
        }
        string ans;
        for(int i=0;i<string1.length();i++){
              int id=string1[i]-'a';
            if(!visited[id]){
                ans+=string1[i];
            }
        }
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string string1,string2;
        cin >> string1; 
        cin >> string2;
        Solution ob;
        cout << ob.removeChars(string1,string2) << endl;
    }
    return 0;
}

// } Driver Code Ends