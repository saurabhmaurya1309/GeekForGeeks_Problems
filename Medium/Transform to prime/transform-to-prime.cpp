//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    int minNumber(int arr[],int N)
    {
        int sum=0;
      
       for(int i=0;i<N;i++){
           sum+=arr[i];
       }
  
      vector<int>dp(sum+1001,true);
      dp[0]=false;
      dp[1]=false;
 
      for(int i=2;i*i<=(sum+1000);i++){
           
           if(dp[i]==true){
                  for(int j=i*i;j<=(sum+1000);j+=i){
              dp[j]=false;
          }
           }
       
      }
      for(int i=sum;i<=sum+1000;i++){
          if(dp[i]==true){
              return i-sum;
          }
      }
       return 0;
        
    
    }
};


//{ Driver Code Starts.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minNumber(arr, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends