//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int index(vector<int>&A, int l, int h,int n){
        while(l<=h){
            int mid=(l+h)/2;
            int next=(mid+1)%n;
            int prev=(mid-1+n)%n;
            if(A[mid]<=A[next]&&A[mid]<=A[prev]){
                return mid;
            }
            else if(A[0]<=A[mid]){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
    }
    int binary(vector<int> &A, int l, int h, int key){
        while(l<=h){
            int mid=(l+h)/2;
            if(A[mid]==key){
                return mid;
            }
            else if(A[mid]<key){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return -1;
        
    }
    int search(int n,vector<int>&A , int key){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        
        //complete the function here
        int l=0;
        int h=n-1;
      int min_index=index(A,l,h,h+1);
    //   cout<<min_index<<endl;
      int first=binary(A,0,min_index-1,key);
      int second=binary(A,min_index,h,key);
      if(first!=-1){
          return first;
      }
      else if(second!=-1){
          return second;
      }
      else{
          return -1;
      }
      
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(n, A, key) << endl;
    }
    return 0;
}
// } Driver Code Ends