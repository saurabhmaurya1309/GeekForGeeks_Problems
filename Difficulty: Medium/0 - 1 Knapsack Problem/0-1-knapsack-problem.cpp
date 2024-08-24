//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    int  solve(int i, int W,vector<int>&wt,vector<int>&val,int currentW,int ans){
        if(currentW>W || i<0 ){
            return ans;
        }
        int take=0;
        if(currentW+wt[i]<=W)
         take = solve(i-1,W,wt,val,currentW+wt[i],ans+val[i]);
        int nottake=solve(i-1,W,wt,val,currentW,ans);
        return max(take,nottake);
    }
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        // Your code here
        int ans=0;
      return  solve(wt.size()-1,W,wt,val,0,ans);
       
    }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends