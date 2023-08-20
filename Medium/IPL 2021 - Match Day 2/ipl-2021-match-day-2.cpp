//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> nums, int n, int k) {
        // your code here
        deque<int>dq;
        vector<int>ans;

        for(int i = 0 ; i<n ;i++){
        //we can keep index of element of nums[i] , which is in range of              window(idx <=i-k)
            while(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }
            //step-2: pop element from deque till we get large element 
            while( !dq.empty() && nums[i] > nums[dq.back()]){
                dq.pop_back();
            }
            // step-3 
            dq.push_back(i);
            //step-4 for every window we store deque front element in ans vector 
            if(i >= k-1){
                ans.push_back(nums[dq.front()]);
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