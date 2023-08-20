//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        
         int i=0;
        int j=0;
        vector<int>ans;
        deque<int>l;
        while(j<n)
        {
            while(l.size()>0 && l.back()<arr[j]){
                l.pop_back();
            }
            l.push_back(arr[j]);
          if(j-i+1<k)  {
              j++;
          }
          else if(j-i+1==k){
              ans.push_back(l.front());
              if(l.front()==arr[i])
              l.pop_front();
              i++;
              j++;
              
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

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends