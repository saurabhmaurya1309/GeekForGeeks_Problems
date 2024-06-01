//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        // code here
        unordered_map<int,int>ump;
        for(int i=0;i<s.length();i++){
            int temp= s[i]-'a'+1;
            ump[temp]++;
        }
        int x=0,y=0;
        for(auto i:ump){
          
            if(i.first%2==0&&i.second%2==0){
                x++;
            }
            else if(i.first%2==1&&i.second%2==1){
                y++;
            }
        }
        int ans=x+y;
        if(ans%2==1){
            return "ODD";
        }
        return "EVEN";
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends