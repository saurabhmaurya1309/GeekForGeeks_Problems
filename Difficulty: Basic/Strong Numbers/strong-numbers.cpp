//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int findfac(int num){
      int ans=1;
      for(int i=1;i<=num;i++){
          ans=ans*i;
      }
      return ans;
  }
    int isStrong(int N) {
        int sum=0;
        int temp=N;
        while(temp){
            int digit=temp%10;
            temp=temp/10;
            sum+=findfac(digit);
        }
        if(sum==N){
            return 1;
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.isStrong(N) << endl;
    }
    return 0;
}
// } Driver Code Ends