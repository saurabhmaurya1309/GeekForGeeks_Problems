//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    long findFirst(vector<long long>v,long long x){
        long start=0;
        long end=v.size()-1;
        long ans=-1;
        while(start<=end){
            long mid=start+(end-start)/2;
            if(v[mid]==x){
                ans=mid;
                end=mid-1;
            }
            else if(v[mid]<x){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
        
    }
    long findLast(vector<long long>v,long long x){
        long start=0;
        long end=v.size()-1;
        long ans=-1;
        while(start<=end){
            long mid=start+(end-start)/2;
            if(v[mid]==x){
                ans=mid;
                start=mid+1;
            }
            else if(v[mid]<x){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
        
    }
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        // code here
        long first=findFirst(v,x);
        long second=findLast(v,x);
        pair<long,long>ans={first,second};
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends