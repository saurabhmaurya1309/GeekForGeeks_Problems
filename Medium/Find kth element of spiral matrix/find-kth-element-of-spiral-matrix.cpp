//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		vector<int>ans;
 		int top=0,left=0,right=m-1,bottom=n-1;
 	
 	  //  left to right
 	  while(left<=right&&top<=bottom){
 	  for(int i=left;i<=right;i++){
 	      ans.push_back(a[top][i]);
 	  }
 	  top++;
 	  //top to bottom
 	  for(int i=top;i<=bottom;i++){
 	      ans.push_back(a[i][right]);
 	  }
 	  right--;
 	  //right to left
 	  for(int i=right;i>=left;i--){
 	      ans.push_back(a[bottom][i]);
 	  }
 	  bottom--;
 	  //bottom to top
 	  for(int i=bottom;i>=top;i--){
 	      ans.push_back(a[i][left]);
 	  }
 	  left++;
 	  
    }
    int cnt=1;
    for(int i=0;i<ans.size();i++){
        // cout<<ans[i]<<" ";
        if(cnt==k){
            return ans[i];
        }
        else{
            cnt++;
    }
    }

    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends