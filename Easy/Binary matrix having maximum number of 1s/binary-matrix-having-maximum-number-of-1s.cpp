//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<int> findMaxRow(vector<vector<int>> mat, int N) {
        //code here
        int mxcount = 0;
        int row_num = 0;
        for(int row=0;row<N;row++){
            int ans=N;
           int start=0;
           int end=N-1;
           while(start<=end){
               int mid=start+(end-start)/2;
               if(mat[row][mid]==1)
               {
                   ans=mid;
                   end=mid-1;
               }
               else{
                   start++;
               }
           }
           int count=N-ans;
           if(count>mxcount){
               mxcount=count;
               row_num=row;
           }
           
        }
        return {row_num,mxcount};
    }
};


//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> arr(n, vector<int> (n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        vector<int> ans = obj.findMaxRow(arr, n);
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends