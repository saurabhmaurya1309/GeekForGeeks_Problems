//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends




// User function Template for C++

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    stack<int>s;
    for(int i=0;i<k;i++){
        int value=q.front();
        q.pop();
        s.push(value);
    }
    while(!s.empty()){
        int value=s.top();
        s.pop();
        q.push(value);
    }
    int n=q.size()-k;
    while(n--){
        int value=q.front();
        q.push(value);
        q.pop();
    }
    return q;
    
    
}