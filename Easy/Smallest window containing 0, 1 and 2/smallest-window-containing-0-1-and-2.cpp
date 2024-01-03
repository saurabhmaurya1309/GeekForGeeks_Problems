//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        // Code here
          int i, j;
        int n = S.size();
        int arr[3] = {0};
        int mini = INT_MAX;

        for (i = 0; i < n; i++) {
            arr[0] = arr[1] = arr[2] = 0;
            
            for (j = i; j < n; j++) {
                arr[S[j] - '0']++;
                
                if (arr[0] && arr[1] && arr[2]) {
                    mini = std::min(mini, j - i + 1);
                    break; 
                }
            }
        }

        return (mini == INT_MAX) ? -1 : mini; 
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends