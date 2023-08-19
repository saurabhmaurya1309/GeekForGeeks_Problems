//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        if(s==0){
            return {-1};
        }
        vector<int>ans;
        int l=0;
        int r=0;
        long long sum=0;
        while(l<n){
            // cout<<sum<<endl;
            // cout<<l<<" "<<r<<endl;
            if(sum==s){
                ans.push_back(l+1);
                ans.push_back(r);
                return ans;
            }
            if(r<n&&sum<s){
                sum+=arr[r];
                r++;
            }
            else{
                sum-=arr[l];
                l++;
            }
        }
        return {-1};
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends