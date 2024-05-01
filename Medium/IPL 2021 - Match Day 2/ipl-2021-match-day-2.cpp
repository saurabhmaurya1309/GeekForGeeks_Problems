//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        vector<int> ans;
    priority_queue<pair<int, int> > heap;
 
    // Initialize the heap with the first k elements
    for (int i = 0; i < k; i++)
        heap.push({ arr[i], i });
 
    // The maximum element in the first window
    ans.push_back(heap.top().first);
 
    // Process the remaining elements
    for (int i = k; i < arr.size(); i++) {
 
        // Add the current element to the heap
        heap.push({ arr[i], i });
 
        // Remove elements that are outside the current
        // window
        while (heap.top().second <= i - k)
            heap.pop();
 
        // The maximum element in the current window
        ans.push_back(heap.top().first);
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