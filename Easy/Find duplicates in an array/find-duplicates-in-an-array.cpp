//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        int f=0;
        sort(arr,arr+n);
        vector<int>vec;
        for(int i=0;i<n;i++){
            if(arr[i]==arr[i+1]){
                f++;
                    if(f==1){
                        vec.push_back(arr[i]);
                        
                    }
            }
            else{
                f=0;
            }
            
        }
        if(vec.size()>0){
            return vec;
        }
        return {-1};
    //       vector<int>v; int flag = 0;
    //   sort(arr,arr+n);
    //   for(int i=0; i<n; i++) {
    //       if(arr[i] == arr[i+1]) {
    //           flag++;
    //           if(flag == 1) {
    //               v.push_back(arr[i]);
    //           }
    //       }
    //       else {
    //           flag = 0;
    //       }
    //   }
    //   if(v.size() > 0) return v;
    //   return {-1};
     }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends