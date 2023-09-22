//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    int first(int arr[],int l,int r,int x){
        int index=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid]==x){
                index=mid;
                r=mid-1;
            }
            else if(arr[mid]>x){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return index;
    }
    int last(int arr[],int l,int r,int x){
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid]==x){
                ans=mid;
                l=mid+1;
            }
            else if(arr[mid]>x){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        int ans1=first(arr,0,n-1,x);
        int ans2=last(arr,0,n-1,x);
        return {ans1,ans2};
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends